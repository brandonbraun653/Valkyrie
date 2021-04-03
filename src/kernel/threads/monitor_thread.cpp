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
#include <Aurora/logging>

/* Chimera Includes */
#include <Chimera/thread>

/* Valkyrie Includes */
#include <src/kernel/threads/thread_listing.hpp>

namespace Valkyrie::Thread::SystemMonitor
{
  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void main( void *arg )
  {
    LOG_INFO( "Monitor thread startup\r\n" );
    while( true )
    {
      Chimera::delayMilliseconds( 100 );
    }
  }
}  // namespace Valkyrie::Thread::Monitor
