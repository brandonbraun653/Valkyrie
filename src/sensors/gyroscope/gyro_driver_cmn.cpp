/********************************************************************************
 *  File Name:
 *    gyro_driver_cmn.cpp
 *
 *  Description:
 *    Common details for the sensor driver
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Includes */
#include <Aurora/logging>

/* Valkyrie Includes */
#include <Valkyrie/kernel>
#include <Valkyrie/sensors>

namespace Valkyrie::Sensor::Gyro
{
  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
  Aurora::Sensor::ISensor_sPtr s_gyro_sensor;

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void initialize()
  {
    using namespace Aurora::Sensor;

    /*-------------------------------------------------
    Already initialized? Don't re-init.
    -------------------------------------------------*/
    if ( s_gyro_sensor )
    {
      return;
    }

    /*-------------------------------------------------
    Configure the target specific sensor implemenation
    -------------------------------------------------*/
#if defined( SIMULATOR )
    std::string_view topic = "gyro";
    size_t tcp_port        = -1;

    Registry::readSafe( Registry::KEY_SIM_PORT_DATA_GYRO, &tcp_port, sizeof( tcp_port ) );
    LOG_DEBUG( "Gyroscope listening on port %ld\r\n", tcp_port );

    auto sensor = new Valkyrie::Sensor::Gyro::Simulated();
    sensor->configureZMQ( tcp_port, topic );
#else
#error "No hardware sensor init"
#endif

    /*-------------------------------------------------
    Configure target independent functionality
    -------------------------------------------------*/
    // sensor->registerCallback( Aurora::Sensor::Event::CB_ON_SAMPLE_SUCCESS, etl::delegate<void( size_t )>::create<onSuccess>()
    // ); sensor->registerCallback( Aurora::Sensor::Event::CB_ON_SAMPLE_FAIL, etl::delegate<void( size_t )>::create<onFail>() );
    s_gyro_sensor = ISensor_sPtr( sensor );
  }


  Aurora::Sensor::ISensor_sPtr getInstance( const size_t instance )
  {
    if ( s_gyro_sensor )
    {
      return s_gyro_sensor;
    }
    else
    {
      return nullptr;
    }
  }

}    // namespace Valkyrie::Sensor::Gyro
