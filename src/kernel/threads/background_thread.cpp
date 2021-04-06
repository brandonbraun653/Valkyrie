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
#include <Valkyrie/kernel>
#include <src/kernel/threads/thread_listing.hpp>

namespace Valkyrie::Thread::Background
{
  /*-------------------------------------------------------------------------------
  Static Declarations
  -------------------------------------------------------------------------------*/
  /**
   * @brief Powers up system resources that require an OS to execute
   * @note  Should be called before the primary system threads are ready to run
   */
  static void bootOSResources();

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void main( void *arg )
  {
    LOG_INFO( "Background thread startup\r\n" );

    /*-------------------------------------------------
    Power up remaining resources
    -------------------------------------------------*/
    bootOSResources();

    /*-------------------------------------------------
    Start up all system threads
    -------------------------------------------------*/
    CreateThreads();

    while( true )
    {
      // Kick watchdog here eventually
      Chimera::delayMilliseconds( 100 );
    }
  }

  /*-------------------------------------------------------------------------------
  Static Implementation
  -------------------------------------------------------------------------------*/
  static void bootOSResources()
  {
    /*-------------------------------------------------
    Load the system config into memory
    -------------------------------------------------*/
    Registry::Boot::loadSystemConfig();
  }
}  // namespace Valkyrie::Thread::Background
