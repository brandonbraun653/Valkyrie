/********************************************************************************
 *  File Name:
 *    main.cpp
 *
 *  Description:
 *    System entry for the full Valkyrie application
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Logging */
#include <Aurora/logging>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/system>
#include <Chimera/thread>

/* Valkyrie Includes */
#include <kernel/startup/sys_init.hpp>

/**
 * @brief Valkyrie main application entry point
 *
 * @return int
 */
int main( void )
{
  /*-------------------------------------------------
  Power up the hardare drivers
  -------------------------------------------------*/
  ChimeraInit();

  /*-------------------------------------------------
  Power up the non-OS aspects of the system
  -------------------------------------------------*/
  Valkyrie::Boot::sysPowerUp();
  LOG_DEBUG( "Hello World\n" );

  /*-------------------------------------------------
  Power up the tasking system. Should never return.
  -------------------------------------------------*/
  Valkyrie::Boot::taskCreate();
  Chimera::Thread::startScheduler();

  /*-------------------------------------------------
  The system should never reach this point, but if it
  does, attempt to gracefully reset everything.
  -------------------------------------------------*/
  Chimera::System::softwareReset();
  return -1;
}
