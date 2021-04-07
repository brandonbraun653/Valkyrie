/********************************************************************************
 *  File Name:
 *    registry_loader.cpp
 *
 *  Description:
 *    Implementations of registry loading from files
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Includes */
#include <Aurora/database>
#include <Aurora/datastore>
#include <Aurora/logging>

/* JSON Includes */
#include <ArduinoJson.hpp>

/* Valkyrie Includes */
#include <Valkyrie/kernel>

namespace Valkyrie::Registry
{
/*-------------------------------------------------------------------------------
Classes
-------------------------------------------------------------------------------*/
/*-------------------------------------------------
Sim Port Configuration
-------------------------------------------------*/
#if defined( SIMULATOR )
  bool SimPortsLoader::registerParameters()
  {
    Chimera::Status_t result = Chimera::Status::OK;
    result |= _Internal::Database.insert( KEY_SIM_PORT_DATA_ACCEL, sizeof( size_t ) );
    result |= _Internal::Database.insert( KEY_SIM_PORT_DATA_GYRO, sizeof( size_t ) );
    result |= _Internal::Database.insert( KEY_SIM_PORT_DATA_MAG, sizeof( size_t ) );

    return result == Chimera::Status::OK;
  }


  bool SimPortsLoader::populateFromFile()
  {
    using namespace ArduinoJson;

    /*-------------------------------------------------
    Allocate buffers for parsing
    -------------------------------------------------*/
    std::string_view filename = "sim_ports.json";
    std::array<uint8_t, 1024> file_buffer;
    file_buffer.fill( 0 );

    StaticJsonDocument<1024> doc;

    /*-------------------------------------------------
    Load the data and parse it
    -------------------------------------------------*/
    Registry::loadData( filename, file_buffer.data(), file_buffer.size() );
    auto error = deserializeJson( doc, file_buffer.data() );
    LOG_IF_ERROR( error == DeserializationError::Ok, "JSON deserialization failed\r\n" );

    /*-------------------------------------------------
    Store the resulting keys into the project registry
    -------------------------------------------------*/
    bool keys_updated = true;

    size_t base_port  = doc[ "base_port" ];
    size_t accel_offset = doc[ "sensors" ][ "accel" ];
    size_t gyro_offset  = doc[ "sensors" ][ "gyro" ];
    size_t mag_offset   = doc[ "sensors" ][ "mag" ];

    size_t accel_port = base_port + accel_offset;
    size_t gyro_port  = base_port + gyro_offset;
    size_t mag_port   = base_port + mag_offset;

    keys_updated |= Registry::writeSafe( DatabaseKeys::KEY_SIM_PORT_DATA_ACCEL, &accel_port, sizeof( accel_port ) );
    keys_updated |= Registry::writeSafe( DatabaseKeys::KEY_SIM_PORT_DATA_GYRO, &gyro_port, sizeof( gyro_port ) );
    keys_updated |= Registry::writeSafe( DatabaseKeys::KEY_SIM_PORT_DATA_MAG, &mag_port, sizeof( mag_port ) );

    return keys_updated;
  }
#endif /* SIMULATOR */

  /*-------------------------------------------------
  Sensor Timing
  -------------------------------------------------*/
  bool SensorTimingLoader::registerParameters()
  {
    Chimera::Status_t result = Chimera::Status::OK;
    result |= _Internal::Database.insert( KEY_SAMPLE_RATE_ACCEL, sizeof( size_t ) );
    result |= _Internal::Database.insert( KEY_SAMPLE_RATE_GYRO, sizeof( size_t ) );
    result |= _Internal::Database.insert( KEY_SAMPLE_RATE_MAG, sizeof( size_t ) );
    result |= _Internal::Database.insert( KEY_SAMPLE_RATE_GPS, sizeof( size_t ) );

    return result == Chimera::Status::OK;
  }


  bool SensorTimingLoader::populateFromFile()
  {
    using namespace ArduinoJson;

    /*-------------------------------------------------
    Allocate buffers for parsing
    -------------------------------------------------*/
    std::string_view filename = "sensor_timing.json";
    std::array<uint8_t, 1024> file_buffer;
    file_buffer.fill( 0 );

    StaticJsonDocument<1024> doc;

    /*-------------------------------------------------
    Load the data and parse it
    -------------------------------------------------*/
    Registry::loadData( filename, file_buffer.data(), file_buffer.size() );
    auto error = deserializeJson( doc, file_buffer.data() );
    LOG_IF_ERROR( error == DeserializationError::Ok, "JSON deserialization failed\r\n" );

    /*-------------------------------------------------
    Store the resulting keys into the project registry
    -------------------------------------------------*/
    bool keys_updated = true;

    size_t accel_rate = doc[ "sensors" ][ "accel" ];
    size_t gyro_rate  = doc[ "sensors" ][ "gyro" ];

    if ( accel_rate == gyro_rate )
    {
      keys_updated |= Registry::writeSafe( DatabaseKeys::KEY_SAMPLE_RATE_ACCEL, &accel_rate, sizeof( accel_rate ) );
      keys_updated |= Registry::writeSafe( DatabaseKeys::KEY_SAMPLE_RATE_GYRO, &gyro_rate, sizeof( gyro_rate ) );
    }
    else
    {
      keys_updated = false;
      LOG_ERROR( "Accelerometer and Gyro sample rate must be the same\r\n" );
    }

    size_t mag_rate = doc[ "sensors" ][ "mag" ];
    keys_updated |= Registry::writeSafe( DatabaseKeys::KEY_SAMPLE_RATE_MAG, &mag_rate, sizeof( mag_rate ) );

    size_t gps_rate = doc[ "sensors" ][ "gps" ];
    keys_updated |= Registry::writeSafe( DatabaseKeys::KEY_SAMPLE_RATE_GPS, &gps_rate, sizeof( gps_rate ) );

    return keys_updated;
  }

}    // namespace Valkyrie::Registry
