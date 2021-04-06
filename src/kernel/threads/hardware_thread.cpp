/********************************************************************************
 *  File Name:
 *    hardware_thread.cpp
 *
 *  Description:
 *    Implements the Valkyrie thread that runs hardware tasks
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Includes */
#include <Aurora/logging>
#include <Aurora/utility>

/* Chimera Includes */
#include <Chimera/thread>

/* Valkyrie Includes */
#include <Valkyrie/sensors>
#include <src/kernel/threads/thread_listing.hpp>

namespace Valkyrie::Thread::HardwareManager
{
  /*-------------------------------------------------------------------------------
  Constants
  -------------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void main( void *arg )
  {
    LOG_INFO( "Hardware thread startup\r\n" );

    /*-------------------------------------------------
    Periodic Timers
    -------------------------------------------------*/
    Aurora::Utility::PeriodicTimeout ahrsTimeout( 10, 0 );

    /*-------------------------------------------------
    Power up various modules
    -------------------------------------------------*/
    Valkyrie::Sensor::Accel::initialize();
    auto accel = Valkyrie::Sensor::Accel::getInstance( 0 );

    /*-------------------------------------------------
    Run the main processing
    -------------------------------------------------*/
    while( true )
    {
      /*-------------------------------------------------
      Measure the attitude sensors
      -------------------------------------------------*/
      if( ahrsTimeout.expired() )
      {
        ahrsTimeout.refresh();

        accel->measure();
        LOG_INFO("Measure\r\n");
      }

      Chimera::delayMilliseconds( HardwareManager::Period );
    }
  }
}  // namespace Valkyrie::Thread::Hardware
