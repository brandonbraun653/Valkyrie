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
  Static Functions
  -------------------------------------------------------------------------------*/
  static void rx_message_pump();
  static void tx_message_pump();

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
      rx_message_pump();
      tx_message_pump();
      Chimera::delayMilliseconds( Sim::Period );
    }
  }

  /*-------------------------------------------------------------------------------
  Static Functions
  -------------------------------------------------------------------------------*/
  static void rx_message_pump()
  {
    using namespace Chimera::Thread;
    using namespace Valkyrie::Sim::Transport;

    for ( size_t topic = Registry::KEY_SIM_TOPIC_START; topic < Registry::KEY_SIM_TOPIC_END; topic++ )
    {
      //LockGuard( queueLock.at( static_cast<Registry::DatabaseKeys>( topic ) ) );


    }
  }


  static void tx_message_pump()
  {
    using namespace Chimera::Thread;
    using namespace Valkyrie::Sim::Transport;

    for ( size_t topic = Registry::KEY_SIM_TOPIC_START; topic < Registry::KEY_SIM_TOPIC_END; topic++ )
    {
      //LockGuard( queueLock.at( static_cast<Registry::DatabaseKeys>( topic ) ) );


    }
  }

}  // namespace Valkyrie::Thread::Hardware
