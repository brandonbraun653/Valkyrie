/********************************************************************************
 *  File Name:
 *    sim_thread.cpp
 *
 *  Description:
 *    Implements the Valkyrie thread that runs the simulator's message pump for
 *    communication with the Virtual Drone.
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Includes */
#include <Aurora/logging>
#include <Aurora/utility>

/* Chimera Includes */
#include <Chimera/thread>

/* Valkyrie Includes */
#include <Valkyrie/autogen>
#include <Valkyrie/kernel>
#include <Valkyrie/sensors>
#include <Valkyrie/sim>
#include <src/kernel/threads/thread_listing.hpp>

namespace Valkyrie::Thread::Sim
{
  /*-------------------------------------------------------------------------------
  Constants
  -------------------------------------------------------------------------------*/
  static constexpr size_t HEARTBEAT_PERIOD_MS = 1000;


  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
  static size_t s_last_tx_heartbeat = 0;


  /*-------------------------------------------------------------------------------
  Static Functions
  -------------------------------------------------------------------------------*/
  static void rx_message_pump();
  static void tx_message_pump();
  static void tx_heartbeat();


  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void main( void *arg )
  {
    LOG_INFO( "Simulator thread startup\r\n" );

    /*-------------------------------------------------
    Power up the simulator thread
    -------------------------------------------------*/
    s_last_tx_heartbeat = Chimera::millis();

    /*-------------------------------------------------
    Run the main processing
    -------------------------------------------------*/
    while( true )
    {
      /*-------------------------------------------------
      Let the simulator know we're alive
      -------------------------------------------------*/
      tx_heartbeat();

      /*-------------------------------------------------
      Perform message pumping to get data from ZMQ into
      the message queues for each topic.
      -------------------------------------------------*/
      rx_message_pump();
      tx_message_pump();

      /*-------------------------------------------------
      Wait until the next time to process. Not really
      concerned with true periodicity, just a relatively
      fast processing speed to move data around.
      -------------------------------------------------*/
      Chimera::delayMilliseconds( Sim::Period );
    }
  }


  /*-------------------------------------------------------------------------------
  Static Functions
  -------------------------------------------------------------------------------*/
  static void tx_heartbeat()
  {
    /*-------------------------------------------------
    Time to transmit the signal?
    -------------------------------------------------*/
    if( !( ( Chimera::millis() - s_last_tx_heartbeat ) >= HEARTBEAT_PERIOD_MS ) )
    {
      return;
    }
    s_last_tx_heartbeat = Chimera::millis();

    /*-------------------------------------------------
    Create the heartbeat object
    -------------------------------------------------*/
    HeartBeat hb;
    hb.timestamp = Chimera::millis();

    /*-------------------------------------------------
    Encode into the protobuf structure
    -------------------------------------------------*/
    uint8_t buffer[ HeartBeat_size ];
    pb_ostream_t outputStream = pb_ostream_from_buffer( buffer, HeartBeat_size );
    bool encodeOK             = pb_encode( &outputStream, HeartBeat_fields, &hb );

    if ( !encodeOK )
    {
      LOG_ERROR( "Failed to encode heartbeat data\n" );
    }

    /*-------------------------------------------------
    Push the data to the remote simulator
    -------------------------------------------------*/
    zmq::message_t message( buffer, HeartBeat_size );
    bool txOK = Valkyrie::Sim::Transport::transmit( Registry::DatabaseKeys::KEY_SIM_PORT_RX_SIM_TOPIC_HEARTBEAT, message );

    if ( !txOK )
    {
      LOG_ERROR( "Failed to transmit heartbeat\n" );
    }

  }


  static void rx_message_pump()
  {
    using namespace Chimera::Thread;
    using namespace Valkyrie::Sim::Transport;

    for ( size_t topic = Registry::KEY_SIM_TOPIC_START; topic < Registry::KEY_SIM_TOPIC_END; topic++ )
    {
      /*-------------------------------------------------
      Make sure the topic resources are initialized and
      it actually is supposed to receive data.
      -------------------------------------------------*/
      auto &tp = ZMQTopics.at( topic );
      if( !tp.mtx || !tp.queue || !tp.socket || tp.transmitType )
      {
        continue;
      }

      LockGuard( *tp.mtx );

      /*-------------------------------------------------
      Grab the received topic and verify it matches
      -------------------------------------------------*/
      zmq::message_t message = {};
      zmq::recv_result_t result = tp.socket->recv( message, zmq::recv_flags::dontwait );
      if ( result <= 0 )
      {
        /* No data to be had yet */
        continue;
      }

      std::string rx_topic( reinterpret_cast<char *>( message.data() ) );
      Registry::TopicString topic_str;
      Registry::readSafe( static_cast<Registry::DatabaseKeys>( topic ), topic_str.data(), topic_str.size() );

      if ( rx_topic.find( std::string_view( topic_str.data() ) ) != 0 )
      {
        /* Topic doesn't match! */
        continue;
      }

      /*-------------------------------------------------
      Grab the data and push to the topic's queue
      -------------------------------------------------*/
      result = tp.socket->recv( message, zmq::recv_flags::dontwait );
      if ( result <= 0 )
      {
        /* No data or wrong size received */
        continue;
      }
      else
      {
        tp.queue->push( std::move( message ) );
        LOG_TRACE( "Received message on topic %s\n", topic_str.data() );
      }
    }
  }


  static void tx_message_pump()
  {
    using namespace Chimera::Thread;
    using namespace Valkyrie::Sim::Transport;

    for ( size_t topic = Registry::KEY_SIM_TOPIC_START; topic < Registry::KEY_SIM_TOPIC_END; topic++ )
    {
      /*-------------------------------------------------
      Make sure the topic resources are initialized and
      it is actually supposed to transmit data.
      -------------------------------------------------*/
      auto &tp = ZMQTopics.at( topic );
      if( !tp.mtx || !tp.queue || !tp.socket || !tp.transmitType )
      {
        continue;
      }

      LockGuard( *tp.mtx );

      /*-------------------------------------------------
      Ensure the queue contains data
      -------------------------------------------------*/
      if ( tp.queue->empty() )
      {
        continue;
      }

      /*-------------------------------------------------
      Grab the topic string associated with this message
      -------------------------------------------------*/
      Registry::TopicString ts;
      ts.fill( 0 );
      Registry::readSafe( static_cast<Registry::DatabaseKeys>( topic ), ts.data(), ts.size() );

      zmq::message_t topic_message( ts.data(), strlen( ts.data() ) );

      /*-------------------------------------------------
      Pull a message from the topic's queue
      -------------------------------------------------*/
      zmq::message_t message = {};
      message.copy( tp.queue->front() );
      tp.queue->pop();

      /*-------------------------------------------------
      Transmit the data
      -------------------------------------------------*/
      tp.socket->send( topic_message, zmq::send_flags::sndmore );
      tp.socket->send( message, zmq::send_flags::dontwait );

      LOG_TRACE( "Sent data on topic: %s\n", ts.data() );
    }
  }

}  // namespace Valkyrie::Thread::Hardware
