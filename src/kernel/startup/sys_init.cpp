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

// Temp Includes
#include <iostream>

namespace Valkyrie::Boot
{
  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
#if defined( CHIMERA_SIMULATOR )
  static Aurora::Logging::CoutSink s_console_sink;
  static Aurora::Logging::SinkHandle s_console_handle;
#endif

  /**
   * @brief A testing thread for the sim
   *
   * @param unused
   */
  static void HelloWorld( void *unused )
  {
    LOG_INFO( "Booting system" );

    while ( true )
    {
      LOG_TRACE( "Hello world" );
      Chimera::delayMilliseconds( 1000 );
    }
  }

  void sysPowerUp()
  {
    using namespace Aurora::Logging;

    /*-------------------------------------------------
    Initialize the framework
    -------------------------------------------------*/
    initialize();
    setGlobalLogLevel( Level::LVL_TRACE );

    /*-------------------------------------------------
    Initialize the console sink
    -------------------------------------------------*/
#if defined( SIMULATOR )
    s_console_sink.setLogLevel( Level::LVL_TRACE );
    s_console_sink.enable();
    s_console_sink.setName( "ConsoleLogger" );

    if ( !s_console_handle )
    {
      s_console_handle = SinkHandle( &s_console_sink );
      registerSink( s_console_handle );
    }
#endif

    /*-------------------------------------------------
    Set the default sink to use
    -------------------------------------------------*/
#if defined( SIMULATOR )
    setRootSink( s_console_handle );
#endif
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
