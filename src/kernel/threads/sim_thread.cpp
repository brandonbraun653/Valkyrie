/********************************************************************************
 *  File Name:
 *    sim_thread.cpp
 *
 *  Description:
 *    Implements the Valkyrie thread that runs the simulator's message pump for
 *    communication with the Virtual Drone.
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
#include <Valkyrie/sim>
#include <src/kernel/threads/thread_listing.hpp>

namespace Valkyrie::Thread::Sim
{
  /*-------------------------------------------------------------------------------
  Constants
  -------------------------------------------------------------------------------*/

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void main( void *arg )
  {
    LOG_INFO( "Simulator thread startup\r\n" );


    /*-------------------------------------------------
    Run the main processing
    -------------------------------------------------*/
    while( true )
    {

      Chimera::delayMilliseconds( Sim::Period );
    }
  }
}  // namespace Valkyrie::Thread::Hardware
