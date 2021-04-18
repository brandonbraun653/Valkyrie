/********************************************************************************
 *  File Name:
 *    sim_transport.cpp
 *
 *  Description:
 *    Implement high level simulator resources
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <cstdio>
#include <cstring>
#include <vector>

/* Aurora Includes */
#include <Aurora/logging>

/* Chimera Includes */
#include <Chimera/thread>

/* Valkyrie Includes */
#include <Valkyrie/kernel>
#include <Valkyrie/sensors>
#include <Valkyrie/sim>

#if defined( SIMULATOR )

namespace Valkyrie::Sim::Transport
{
  /*-------------------------------------------------------------------------------
  Static Functions
  -------------------------------------------------------------------------------*/
  /**
   * @brief Open the simulator sockets
   */
  static void openSockets();

  /**
   * @brief Registers topics that are used for transporting data around
   */
  static void registerTopics();

  /**
   * @brief Builds the ZMQ address to connect to
   *
   * @param tcp_port      Which TCP port is used
   * @return std::string
   */
  static std::string buildAddress( const size_t tcp_port );

  /*-------------------------------------------------------------------------------
  Public Data
  -------------------------------------------------------------------------------*/
  zmq::context_t ZMQContext;
  MappedSocket ZMQSockets;
  MappedTopic ZMQTopics;

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void initTransport( const size_t threads )
  {
    LOG_TRACE( "Powering up ZMQ transport\r\n" );
    ZMQContext = zmq::context_t( threads );

    /*-------------------------------------------------
    Register transport topics with the system registry
    -------------------------------------------------*/
    registerTopics();

    /*-------------------------------------------------
    Open various sockets
    -------------------------------------------------*/
    openSockets();

    /*-------------------------------------------------
    Initialize topic resources to defaults
    -------------------------------------------------*/
    for ( size_t topic = Registry::KEY_SIM_TOPIC_START; topic < Registry::KEY_SIM_TOPIC_END; topic++ )
    {
      ZMQTopics.insert( { topic, TopicResource() } );
      TopicResource &tp = ZMQTopics.at( topic );

      tp.mtx    = new Chimera::Thread::RecursiveMutex();
      tp.queue  = new MessageQueue();
      tp.socket = nullptr;
    }

    /*-------------------------------------------------
    Map SENSOR topics to their associated socket
    -------------------------------------------------*/
    TopicResource &accel = ZMQTopics.at( Registry::KEY_SIM_PORT_SENSOR_TOPIC_ACCEL );
    accel.key            = Registry::KEY_SIM_PORT_SENSOR_TOPIC_ACCEL;
    accel.transmitType   = false;
    accel.socket         = ZMQSockets.at( Registry::KEY_SIM_PORT_SENSOR );

    TopicResource &gyro = ZMQTopics.at( Registry::KEY_SIM_PORT_SENSOR_TOPIC_GYRO );
    gyro.key            = Registry::KEY_SIM_PORT_SENSOR_TOPIC_GYRO;
    gyro.transmitType   = false;
    gyro.socket         = ZMQSockets.at( Registry::KEY_SIM_PORT_SENSOR );

    TopicResource &mag = ZMQTopics.at( Registry::KEY_SIM_PORT_SENSOR_TOPIC_MAG );
    mag.key            = Registry::KEY_SIM_PORT_SENSOR_TOPIC_MAG;
    mag.transmitType   = false;
    mag.socket         = ZMQSockets.at( Registry::KEY_SIM_PORT_SENSOR );

    /*-------------------------------------------------
    Map USR_INPUT topics to their associated socket
    -------------------------------------------------*/
    TopicResource &usr_input = ZMQTopics.at( Registry::KEY_SIM_PORT_USR_INPUT_TOPIC_SET_POINT );
    usr_input.key            = Registry::KEY_SIM_PORT_USR_INPUT_TOPIC_SET_POINT;
    usr_input.transmitType   = false;
    usr_input.socket         = ZMQSockets.at( Registry::KEY_SIM_PORT_USR_INPUT );

    /*-------------------------------------------------
    Map TX_SIM topics to their associated socket
    -------------------------------------------------*/
    TopicResource &tx_hb = ZMQTopics.at( Registry::KEY_SIM_PORT_TX_SIM_TOPIC_HEARTBEAT );
    tx_hb.key            = Registry::KEY_SIM_PORT_TX_SIM_TOPIC_HEARTBEAT;
    tx_hb.transmitType   = false;
    tx_hb.socket         = ZMQSockets.at( Registry::KEY_SIM_PORT_TX_SIM );

    /*-------------------------------------------------
    Map RX_SIM topics to their associated socket
    -------------------------------------------------*/
    TopicResource &rx_hb = ZMQTopics.at( Registry::KEY_SIM_PORT_RX_SIM_TOPIC_HEARTBEAT );
    rx_hb.key            = Registry::KEY_SIM_PORT_RX_SIM_TOPIC_HEARTBEAT;
    rx_hb.transmitType   = true;
    rx_hb.socket         = ZMQSockets.at( Registry::KEY_SIM_PORT_RX_SIM );

    /*-------------------------------------------------
    Map SYS_CTRL topics to their associated socket
    -------------------------------------------------*/
    TopicResource &motor_ctrl = ZMQTopics.at( Registry::KEY_SIM_PORT_SYS_CTRL_TOPIC_MOTOR );
    motor_ctrl.key            = Registry::KEY_SIM_PORT_SYS_CTRL_TOPIC_MOTOR;
    motor_ctrl.transmitType   = true;
    motor_ctrl.socket         = ZMQSockets.at( Registry::KEY_SIM_PORT_SYS_CTRL );
  }


  bool transmit( Registry::DatabaseKeys topic, zmq::message_t &msg )
  {
    /*-------------------------------------------------
    Acquire exclusive access to the resource
    -------------------------------------------------*/
    TopicResource &tp = ZMQTopics.at( static_cast<size_t>( topic ) );
    Chimera::Thread::LockGuard( *tp.mtx );

    /*-------------------------------------------------
    Protect against the topic only being for RX-ing
    -------------------------------------------------*/
    if ( !tp.transmitType )
    {
      LOG_ERROR( "Tried to transmit on topic %d, but it's not of transmit type", topic );
      return false;
    }

    /*-------------------------------------------------
    Push a message into the topic's queue
    -------------------------------------------------*/
    tp.queue->push( std::move( msg ) );
    return true;
  }


  bool receive( Registry::DatabaseKeys topic, zmq::message_t &msg )
  {
    /*-------------------------------------------------
    Acquire exclusive access to the resource
    -------------------------------------------------*/
    TopicResource &tp = ZMQTopics.at( static_cast<size_t>( topic ) );
    Chimera::Thread::LockGuard( *tp.mtx );

    /*-------------------------------------------------
    Protect against the topic only being for TX-ing
    -------------------------------------------------*/
    if ( tp.transmitType )
    {
      return false;
    }

    /*-------------------------------------------------
    Pull a message from the topic's queue
    -------------------------------------------------*/
    if ( !tp.queue->empty() )
    {
      msg.copy( tp.queue->front() );
      tp.queue->pop();
      return true;
    }
    else
    {
      return false;
    }
  }


  static void openSockets()
  {
    Registry::DatabaseKeys key;
    size_t port;
    std::array<char, Registry::sim_TOPIC_STR_SIZE> topic;

    /*-------------------------------------------------------------------------------
    Open the Sensor socket, which is used to pull sensor readings provided by the
    drone simulation engine.
    -------------------------------------------------------------------------------*/
    key  = Registry::KEY_SIM_PORT_SENSOR;
    port = 0;
    topic.fill( 0 );

    /* Create the socket */
    ZMQSockets.insert( std::make_pair( key, std::make_shared<zmq::socket_t>( ZMQContext, ZMQ_SUB ) ) );

    /* Figure out the specific port to connect to */
    Registry::readSafe( key, &port, sizeof( port ) );
    ZMQSockets.at( key )->connect( buildAddress( port ) );
    LOG_INFO( "Sensor port listening on %s\n", buildAddress( port ).c_str() );

    /* Subscribe to the known topics */
    topic.fill( 0 );
    Registry::readSafe( Registry::KEY_SIM_PORT_SENSOR_TOPIC_ACCEL, topic.data(), topic.size() );
    ZMQSockets.at( key )->setsockopt( ZMQ_SUBSCRIBE, topic.data(), strlen( topic.data() ) );

    topic.fill( 0 );
    Registry::readSafe( Registry::KEY_SIM_PORT_SENSOR_TOPIC_GYRO, topic.data(), topic.size() );
    ZMQSockets.at( key )->setsockopt( ZMQ_SUBSCRIBE, topic.data(), strlen( topic.data() ) );

    topic.fill( 0 );
    Registry::readSafe( Registry::KEY_SIM_PORT_SENSOR_TOPIC_MAG, topic.data(), topic.size() );
    ZMQSockets.at( key )->setsockopt( ZMQ_SUBSCRIBE, topic.data(), strlen( topic.data() ) );


    /*-------------------------------------------------------------------------------
    Open the User Input socket, which is used to read user input coming from the
    drone simulation software. Usually this is some kind of high level event input
    information like button presses, etc.
    -------------------------------------------------------------------------------*/
    key  = Registry::KEY_SIM_PORT_USR_INPUT;
    port = 0;
    topic.fill( 0 );

    /* Create the socket */
    ZMQSockets.insert( std::make_pair( key, std::make_shared<zmq::socket_t>( ZMQContext, ZMQ_SUB ) ) );

    /* Figure out the specific port to connect to */
    Registry::readSafe( key, &port, sizeof( port ) );
    ZMQSockets.at( key )->connect( buildAddress( port ) );
    LOG_INFO( "User input port listening on %s\n", buildAddress( port ).c_str() );

    /* Subscribe to the known topics */
    topic.fill( 0 );
    Registry::readSafe( Registry::KEY_SIM_PORT_USR_INPUT_TOPIC_SET_POINT, topic.data(), topic.size() );
    ZMQSockets.at( key )->setsockopt( ZMQ_SUBSCRIBE, topic.data(), strlen( topic.data() ) );


    /*-------------------------------------------------------------------------------
    Open the TX SIM socket, which allows flight software to listen to generic info
    being transmitted from the drone simulator.
    -------------------------------------------------------------------------------*/
    key  = Registry::KEY_SIM_PORT_TX_SIM;
    port = 0;
    topic.fill( 0 );

    /* Create the socket */
    ZMQSockets.insert( std::make_pair( key, std::make_shared<zmq::socket_t>( ZMQContext, ZMQ_SUB ) ) );

    /* Figure out the specific port to connect to */
    Registry::readSafe( key, &port, sizeof( port ) );
    ZMQSockets.at( key )->connect( buildAddress( port ) );
    LOG_INFO( "Flight software listening to SIM on %s\n", buildAddress( port ).c_str() );

    /* Subscribe to the known topics */
    topic.fill( 0 );
    Registry::readSafe( Registry::KEY_SIM_PORT_TX_SIM_TOPIC_HEARTBEAT, topic.data(), topic.size() );
    ZMQSockets.at( key )->setsockopt( ZMQ_SUBSCRIBE, topic.data(), strlen( topic.data() ) );


    /*-------------------------------------------------------------------------------
    Open the System Control port, which is used by the flight software to transmit
    motor control signals into the drone simulator.
    -------------------------------------------------------------------------------*/
    key  = Registry::KEY_SIM_PORT_SYS_CTRL;
    port = 0;

    /* Create the socket */
    ZMQSockets.insert( std::make_pair( key, std::make_shared<zmq::socket_t>( ZMQContext, ZMQ_PUB ) ) );

    /* Figure out the specific port to bind to */
    Registry::readSafe( key, &port, sizeof( port ) );
    ZMQSockets.at( key )->bind( buildAddress( port ) );
    LOG_INFO( "System control port transmitting on %s\n", buildAddress( port ).c_str() );

    /*-------------------------------------------------------------------------------
    Open the SIM RX port, which the flight software uses to transmit info to the sim.
    Ie, the sim is listening on this port for information. It's the generic pipe for
    all kinds of data in this direction.
    -------------------------------------------------------------------------------*/
    key  = Registry::KEY_SIM_PORT_RX_SIM;
    port = 0;

    /* Create the socket */
    ZMQSockets.insert( std::make_pair( key, std::make_shared<zmq::socket_t>( ZMQContext, ZMQ_PUB ) ) );

    /* Figure out the specific port to bind to */
    Registry::readSafe( key, &port, sizeof( port ) );
    ZMQSockets.at( key )->bind( buildAddress( port ) );
    LOG_INFO( "Flight software transmitting to SIM on %s\n", buildAddress( port ).c_str() );
  }


  static void registerTopics()
  {
    using namespace Valkyrie::Registry;

    char topic[ DatabaseKeys::sim_TOPIC_STR_SIZE ];

    /*-------------------------------------------------
    Initialize port topic fields
    -------------------------------------------------*/
    _Internal::Database.insert( KEY_SIM_PORT_SENSOR_TOPIC_ACCEL, sim_TOPIC_STR_SIZE );
    _Internal::Database.insert( KEY_SIM_PORT_SENSOR_TOPIC_GYRO, sim_TOPIC_STR_SIZE );
    _Internal::Database.insert( KEY_SIM_PORT_SENSOR_TOPIC_MAG, sim_TOPIC_STR_SIZE );
    _Internal::Database.insert( KEY_SIM_PORT_SYS_CTRL_TOPIC_MOTOR, sim_TOPIC_STR_SIZE );
    _Internal::Database.insert( KEY_SIM_PORT_USR_INPUT_TOPIC_SET_POINT, sim_TOPIC_STR_SIZE );
    _Internal::Database.insert( KEY_SIM_PORT_TX_SIM_TOPIC_HEARTBEAT, sim_TOPIC_STR_SIZE );
    _Internal::Database.insert( KEY_SIM_PORT_RX_SIM_TOPIC_HEARTBEAT, sim_TOPIC_STR_SIZE );

    /*-------------------------------------------------
    Register each topic string. Note that this must
    match what's found in the Python simulator in file
    connection.py.
    -------------------------------------------------*/
    snprintf( topic, sim_TOPIC_STR_SIZE, "accel" );
    Registry::writeSafe( DatabaseKeys::KEY_SIM_PORT_SENSOR_TOPIC_ACCEL, topic, sim_TOPIC_STR_SIZE );

    snprintf( topic, sim_TOPIC_STR_SIZE, "gyro" );
    Registry::writeSafe( DatabaseKeys::KEY_SIM_PORT_SENSOR_TOPIC_GYRO, topic, sim_TOPIC_STR_SIZE );

    snprintf( topic, sim_TOPIC_STR_SIZE, "mag" );
    Registry::writeSafe( DatabaseKeys::KEY_SIM_PORT_SENSOR_TOPIC_MAG, topic, sim_TOPIC_STR_SIZE );

    snprintf( topic, sim_TOPIC_STR_SIZE, "motor" );
    Registry::writeSafe( DatabaseKeys::KEY_SIM_PORT_SYS_CTRL_TOPIC_MOTOR, topic, sim_TOPIC_STR_SIZE );

    snprintf( topic, sim_TOPIC_STR_SIZE, "setpoint" );
    Registry::writeSafe( DatabaseKeys::KEY_SIM_PORT_USR_INPUT_TOPIC_SET_POINT, topic, sim_TOPIC_STR_SIZE );

    snprintf( topic, sim_TOPIC_STR_SIZE, "tx_heartbeat" );
    Registry::writeSafe( DatabaseKeys::KEY_SIM_PORT_TX_SIM_TOPIC_HEARTBEAT, topic, sim_TOPIC_STR_SIZE );

    snprintf( topic, sim_TOPIC_STR_SIZE, "rx_heartbeat" );
    Registry::writeSafe( DatabaseKeys::KEY_SIM_PORT_RX_SIM_TOPIC_HEARTBEAT, topic, sim_TOPIC_STR_SIZE );
  }


  static std::string buildAddress( const size_t tcp_port )
  {
    char fmtBuffer[ 100 ];
    memset( fmtBuffer, 0, sizeof( fmtBuffer ) );

    snprintf( fmtBuffer, sizeof( fmtBuffer ), "tcp://127.0.0.1:%ld", tcp_port );

    return std::string( fmtBuffer );
  }

}    // namespace Valkyrie::Sim::Transport

#endif /* SIMULATOR */
