/********************************************************************************
 *  File Name:
 *    thread_listing.cpp
 *
 *  Description:
 *    Powers up the system threads
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Valkyrie Includes */
#include <src/kernel/threads/thread_listing.hpp>

namespace Valkyrie::Thread
{
  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void CreateThreads()
  {
    using namespace Chimera::Thread;
    using namespace Valkyrie::Thread;

    /*-------------------------------------------------
    Hardware Manager
    -------------------------------------------------*/
    TaskConfig cfg;
    cfg.function.callable.pointer = HardwareManager::main;
    cfg.function.type             = FunctorType::C_STYLE;
    cfg.name                      = HardwareManager::Name.data();
    cfg.priority                  = 4;
    cfg.stackWords                = HardwareManager::StackDepth;
    cfg.arg                       = nullptr;
    cfg.type                      = TaskInitType::DYNAMIC;

    Task hwm;
    hwm.create( cfg );
    hwm.start();

    /*-------------------------------------------------
    System Monitor
    -------------------------------------------------*/
    cfg.function.callable.pointer = SystemMonitor::main;
    cfg.function.type             = FunctorType::C_STYLE;
    cfg.name                      = SystemMonitor::Name.data();
    cfg.priority                  = 4;
    cfg.stackWords                = SystemMonitor::StackDepth;
    cfg.arg                       = nullptr;
    cfg.type                      = TaskInitType::DYNAMIC;

    Task sys;
    sys.create( cfg );
    sys.start();

    /*-------------------------------------------------
    Simulator Thread
    -------------------------------------------------*/
#if defined( SIMULATOR )
    cfg.function.callable.pointer = Sim::main;
    cfg.function.type             = FunctorType::C_STYLE;
    cfg.name                      = Sim::Name.data();
    cfg.priority                  = 5;
    cfg.stackWords                = Sim::StackDepth;
    cfg.arg                       = nullptr;
    cfg.type                      = TaskInitType::DYNAMIC;

    Task sim;
    sim.create( cfg );
    sim.start();
#endif  /* SIMULATOR */

  }
}  // namespace Valkyrie::Thread
