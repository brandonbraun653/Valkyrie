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
#include <Valkyrie/kernel>
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
    Power up various modules
    -------------------------------------------------*/
    Sensor::initIMU();

    /*-------------------------------------------------
    Run the main processing
    -------------------------------------------------*/
    while( true )
    {
      /*-------------------------------------------------
      Measure the attitude sensors
      -------------------------------------------------*/
      Sensor::processIMU();

      Chimera::delayMilliseconds( HardwareManager::Period );
    }
  }
}  // namespace Valkyrie::Thread::Hardware
