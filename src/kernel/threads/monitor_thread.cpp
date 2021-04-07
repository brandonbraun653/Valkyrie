/********************************************************************************
 *  File Name:
 *    monitor_thread.cpp
 *
 *  Description:
 *    Implements the Valkyrie thread that runs monitor tasks
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Includes */
#include <Aurora/sensors>
#include <Aurora/logging>

/* Chimera Includes */
#include <Chimera/thread>

/* Valkyrie Includes */
#include <Valkyrie/kernel>
#include <src/kernel/threads/thread_listing.hpp>

namespace Valkyrie::Thread::SystemMonitor
{
  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void main( void *arg )
  {
    LOG_INFO( "Monitor thread startup\r\n" );

    Aurora::Sensor::TriAxisSample sensorData;

    while( true )
    {
      if( Registry::readSafe( Registry::KEY_SENSOR_DATA_ACCEL, &sensorData, sizeof( sensorData ) ) )
      {
        LOG_DEBUG( "Accel: [x:%2.2f, y:%2.2f, z:%2.2f]\r\n", sensorData.x, sensorData.y, sensorData.z );
      }


      Chimera::delayMilliseconds( 100 );
    }
  }
}  // namespace Valkyrie::Thread::Monitor
