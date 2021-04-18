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
  Static Functions
  -------------------------------------------------------------------------------*/
  static void rx_message_pump();
  static void tx_message_pump();

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void main( void *arg )
  {
    LOG_INFO( "Simulator thread startup\r\n" );

    /*-------------------------------------------------
    Run the main processing
    -------------------------------------------------*/
    while( true )
    {
      rx_message_pump();
      tx_message_pump();
      Chimera::delayMilliseconds( Sim::Period );
    }
  }

  /*-------------------------------------------------------------------------------
  Static Functions
  -------------------------------------------------------------------------------*/
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
      Pull a message from the topic's queue
      -------------------------------------------------*/
      zmq::message_t message = {};
      message.copy( tp.queue->front() );
      tp.queue->pop();

      /*-------------------------------------------------
      Transmit the data
      -------------------------------------------------*/
      tp.socket->send( message, zmq::send_flags::dontwait );
    }
  }

}  // namespace Valkyrie::Thread::Hardware
