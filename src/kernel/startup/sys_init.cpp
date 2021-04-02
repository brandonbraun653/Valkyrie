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

// Testing only
#include <etl/delegate.h>
#include <Valkyrie/sensors>
#include <thread>

namespace Valkyrie::Boot
{
  static std::thread zmqThread;

  /**
   * @brief A testing thread for the sim
   *
   * @param unused
   */
  static void HelloWorld( void *unused )
  {
    LOG_INFO( "Booting system\r\n" );

    Valkyrie::Sensor::Accel::initialize();


    while ( true )
    {
      Chimera::delayMilliseconds( 1000 );
    }
  }

  static void HelloUniverse( void *unused )
  {

    Chimera::delayMilliseconds( 100 );
    auto sensor = Valkyrie::Sensor::Accel::getInstance( 0 );

    while( true )
    {
      sensor->measure();
      Chimera::delayMilliseconds( 50 );
    }
  }

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

  void createTasks()
  {
    using namespace Chimera::Thread;
    TaskConfig cfg;

    /*-------------------------------------------------
    Test thread 0
    -------------------------------------------------*/
    cfg.function.callable.pointer = HelloWorld;
    cfg.function.type             = FunctorType::C_STYLE;
    cfg.name                      = "HelloWorld";
    cfg.priority                  = Priority::LEVEL_3;
    cfg.stackWords                = 1024;
    cfg.arg                       = nullptr;
    cfg.type                      = TaskInitType::DYNAMIC;

    Task hw;
    hw.create( cfg );
    hw.start();

    /*-------------------------------------------------
    Test thread 1
    -------------------------------------------------*/
    cfg.function.callable.pointer = HelloUniverse;
    cfg.function.type             = FunctorType::C_STYLE;
    cfg.name                      = "HelloUniverse";
    cfg.priority                  = Priority::LEVEL_3;
    cfg.stackWords                = 1024;
    cfg.arg                       = nullptr;
    cfg.type                      = TaskInitType::DYNAMIC;

    Task hu;
    hu.create( cfg );
    hu.start();
  }

}    // namespace Valkyrie::Boot
