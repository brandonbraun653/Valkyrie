/********************************************************************************
 *  File Name:
 *    background_thread.cpp
 *
 *  Description:
 *    Implements the Valkyrie thread that runs background tasks
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Includes */
#include <Aurora/logging>

/* Chimera Includes */
#include <Chimera/thread>

/* Valkyrie Includes */
#include <src/kernel/threads/thread_listing.hpp>

namespace Valkyrie::Thread::Background
{
  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void main( void *arg )
  {
    LOG_INFO( "Background thread startup\r\n" );

    /*-------------------------------------------------
    Start up the remaining system threads
    -------------------------------------------------*/
    CreateThreads();

    while( true )
    {
      // Kick watchdog here eventually
      Chimera::delayMilliseconds( 100 );
    }
  }
}  // namespace Valkyrie::Thread::Background
