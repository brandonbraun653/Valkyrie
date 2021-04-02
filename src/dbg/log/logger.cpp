/********************************************************************************
 *  File Name:
 *    logger.cpp
 *
 *  Description:
 *    Project logger implementation details
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Logging */
#include <Aurora/logging>

/* Project Includes */
#include <src/dbg/log/logger.hpp>

namespace Valkyrie::Log
{
  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
#if defined( CHIMERA_SIMULATOR )
  static Aurora::Logging::CoutSink s_console_sink;
  static Aurora::Logging::SinkHandle s_console_handle;
#endif

  /*-------------------------------------------------------------------------------
  Boot Namespace
  -------------------------------------------------------------------------------*/
  namespace Boot
  {
    void initLoggers()
    {
      using namespace Aurora::Logging;

      /*-------------------------------------------------
      Initialize the framework
      -------------------------------------------------*/
      Aurora::Logging::initialize();
      Aurora::Logging::setGlobalLogLevel( Level::LVL_TRACE );

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

  }    // namespace Boot
}    // namespace Valkyrie::Log
