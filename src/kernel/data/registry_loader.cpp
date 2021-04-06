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

    size_t accel_sample_rate = doc[ "sensors" ][ "accel" ];
    keys_updated |= Registry::writeSafe( DatabaseKeys::KEY_SAMPLE_RATE_ACCEL, &accel_sample_rate, sizeof( accel_sample_rate ) );

    size_t gyro_sample_rate = doc[ "sensors" ][ "gyro" ];
    keys_updated |= Registry::writeSafe( DatabaseKeys::KEY_SAMPLE_RATE_GYRO, &gyro_sample_rate, sizeof( gyro_sample_rate ) );

    size_t mag_sample_rate = doc[ "sensors" ][ "mag" ];
    keys_updated |= Registry::writeSafe( DatabaseKeys::KEY_SAMPLE_RATE_MAG, &mag_sample_rate, sizeof( mag_sample_rate ) );

    size_t gps_sample_rate = doc[ "sensors" ][ "gps" ];
    keys_updated |= Registry::writeSafe( DatabaseKeys::KEY_SAMPLE_RATE_GPS, &gps_sample_rate, sizeof( gps_sample_rate ) );

    return keys_updated;
  }
}    // namespace Valkyrie::Registry
