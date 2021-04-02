/********************************************************************************
 *  File Name:
 *    virtual_sensor.cpp
 *
 *  Description:
 *    Implement high level virtual sensor resources
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <cstdio>
#include <cstring>

/* Aurora Includes */
#include <Aurora/logging>

/* Valkyrie Includes */
#include <Valkyrie/sensors>

#if defined( SIMULATOR )

namespace Valkyrie::Sensor::Virtual
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
    LOG_TRACE( "Powering up ZMQ sensor transport\r\n" );
    ZMQContext = zmq::context_t( threads );
  }


  std::string buildAddress( const size_t tcp_port )
  {
    char fmtBuffer[ 100 ];
    memset( fmtBuffer, 0, sizeof( fmtBuffer ) );

    snprintf( fmtBuffer, sizeof( fmtBuffer ), "tcp://127.0.0.1:%ld", tcp_port );

    return std::string( fmtBuffer );
  }

}  // namespace Valkyrie::Sensor::Virtual

#endif  /* SIMULATOR */
