/********************************************************************************
 *  File Name:
 *    accel_driver_cmn.cpp
 *
 *  Description:
 *    Common details for the sensor driver
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Includes */
#include <Aurora/logging>

/* Valkyrie Includes */
#include <Valkyrie/sensors>

namespace Valkyrie::Sensor::Accel
{
  /** Testing only **/
  static void onSuccess( const size_t unused )
  {
    LOG_TRACE( "Sample success!\r\n" );
  }

  static void onFail( const size_t unused )
  {
    LOG_TRACE( "Sample fail!\r\n" );
  }

  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
  std::shared_ptr<Aurora::Sensor::IBase> s_accel_sensor;

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void initialize()
  {
    if( s_accel_sensor )
    {
      return;
    }

    #if defined( SIMULATOR )
    std::string_view topic = "accel";
    size_t tcp_port = 50024;

    auto sensor = new Valkyrie::Sensor::Accel::Simulated();
    sensor->configureZMQ( tcp_port, topic );
    #else
    #error "No hardware sensor init"
    #endif


    sensor->registerCallback( Aurora::Sensor::Event::CB_ON_SAMPLE_SUCCESS, etl::delegate<void( size_t )>::create<onSuccess>() );
    sensor->registerCallback( Aurora::Sensor::Event::CB_ON_SAMPLE_FAIL, etl::delegate<void( size_t )>::create<onFail>() );
    s_accel_sensor = std::shared_ptr<Aurora::Sensor::IBase>( sensor );
  }


  std::shared_ptr<Aurora::Sensor::IBase> getInstance( const size_t instance )
  {
    if( s_accel_sensor )
    {
      return s_accel_sensor;
    }
    else
    {
      return nullptr;
    }
  }

}  // namespace Valkyrie::Sensor::Accel
