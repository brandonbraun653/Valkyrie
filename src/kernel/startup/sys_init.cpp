/********************************************************************************
 *  File Name:
 *    sys_init.cpp
 *
 *  Description:
 *    System init sequences for bootup
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Logging */
#include <Aurora/logging>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/thread>

/* Valkyrie Includes */
#include <Valkyrie/debug>
#include <Valkyrie/kernel>
#include <Valkyrie/sensors>
#include <src/kernel/threads/thread_listing.hpp>

namespace Valkyrie::Boot
{
  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void sysPowerUp()
  {
    /*-------------------------------------------------
    Power up the debug system
    -------------------------------------------------*/
    Log::Boot::initLoggers();

    /*-------------------------------------------------
    Power up the database/registry system
    -------------------------------------------------*/
    Registry::Boot::initRegistry();

    /*-------------------------------------------------
    If running on a simulator, power up communication
    layer between the sim and this project.
    -------------------------------------------------*/
#if defined( SIMULATOR )
    Sensor::Virtual::initTransport( 8 );
#endif /* SIMULATOR */
  }


  void createBackgroundThread()
  {
    using namespace Chimera::Thread;
    using namespace Valkyrie::Thread;

    /*-------------------------------------------------
    Register the background thread. This will in turn
    boot the remaining system threads once it starts.
    -------------------------------------------------*/
    TaskConfig cfg;
    cfg.function.callable.pointer = Background::main;
    cfg.function.type             = FunctorType::C_STYLE;
    cfg.name                      = Background::Name.data();
    cfg.priority                  = Priority::LEVEL_1;
    cfg.stackWords                = Background::StackDepth;
    cfg.arg                       = nullptr;
    cfg.type                      = TaskInitType::DYNAMIC;

    Task background;
    background.create( cfg );
    background.start();
  }

}    // namespace Valkyrie::Boot
