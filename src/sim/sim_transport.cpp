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

/* Aurora Includes */
#include <Aurora/logging>

/* Valkyrie Includes */
#include <Valkyrie/kernel>
#include <Valkyrie/sim>

#if defined( SIMULATOR )

namespace Valkyrie::Sim::Transport
{
  /*-------------------------------------------------------------------------------
  Public Data
  -------------------------------------------------------------------------------*/
  zmq::context_t ZMQContext;

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void initTransport( const size_t threads )
  {
    LOG_TRACE( "Powering up ZMQ transport\r\n" );
    ZMQContext = zmq::context_t( threads );
  }


  void registerTopics()
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

    snprintf( topic, sim_TOPIC_STR_SIZE, "rx_hearbeat" );
    Registry::writeSafe( DatabaseKeys::KEY_SIM_PORT_RX_SIM_TOPIC_HEARTBEAT, topic, sim_TOPIC_STR_SIZE );
  }


  std::string buildAddress( const size_t tcp_port )
  {
    char fmtBuffer[ 100 ];
    memset( fmtBuffer, 0, sizeof( fmtBuffer ) );

    snprintf( fmtBuffer, sizeof( fmtBuffer ), "tcp://127.0.0.1:%ld", tcp_port );

    return std::string( fmtBuffer );
  }

}    // namespace Valkyrie::Sim::Transport

#endif /* SIMULATOR */
