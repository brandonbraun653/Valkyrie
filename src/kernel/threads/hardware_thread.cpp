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

/* Chimera Includes */
#include <Chimera/thread>

/* Valkyrie Includes */
#include <Valkyrie/sensors>
#include <src/kernel/threads/thread_listing.hpp>

namespace Valkyrie::Thread::HardwareManager
{
  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void main( void *arg )
  {
    LOG_INFO( "Hardware thread startup\r\n" );

    Valkyrie::Sensor::Accel::initialize();
    auto sensor = Valkyrie::Sensor::Accel::getInstance( 0 );

    while( true )
    {
      sensor->measure();
      Chimera::delayMilliseconds( 50 );
    }
  }
}  // namespace Valkyrie::Thread::Hardware
