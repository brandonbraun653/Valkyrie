/********************************************************************************
 *  File Name:
 *    sys_init.cpp
 *
 *  Description:
 *    System init sequences for bootup
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/thread>

// Temp Includes
#include <iostream>

namespace Valkyrie::Boot
{
  /**
   * @brief A testing thread for the sim
   *
   * @param unused
   */
  static void HelloWorld( void *unused )
  {
    std::cout << "Booting system" << std::endl;

    while ( true )
    {
      std::cout << "Hello world" << std::endl;
      Chimera::delayMilliseconds( 1000 );
    }
  }

  void sysPowerUp()
  {
  }

  void taskCreate()
  {
    using namespace Chimera::Thread;

    /*-------------------------------------------------
    Just for testing, create the hello world thread
    -------------------------------------------------*/
    TaskConfig cfg;
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
  }

}    // namespace Valkyrie::Boot
