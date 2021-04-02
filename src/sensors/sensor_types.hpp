/********************************************************************************
 *  File Name:
 *    sensorypes.hpp
 *
 *  Description:
 *    High level types to support all generic sensor classes
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef SENSOR_INTERFACE_TYPES_HPP
#define SENSOR_INTERFACE_TYPES_HPP

/* STL Includes */
#include <cstdint>
#include <cstddef>
#include <cstring>

namespace Valkyrie::Sensor
{
  /*-------------------------------------------------------------------------------
  Enumerations
  -------------------------------------------------------------------------------*/
  /**
   * @brief What type of sensors are supported
   */
  enum class Variant : uint8_t
  {
    ACCELEROMETER,
    GYROSCOPE,
    MAGNETOMETER,

    NUM_OPTIONS,
    INVALID
  };

  /**
   * @brief Event types that observers may register callbacks against
   */
  enum class Event : size_t
  {
    CB_UNHANDLED,         /**< Required id for default handler */
    CB_ON_SAMPLE_SUCCESS, /**< A sample operation succeeded */
    CB_ON_SAMPLE_FAIL,    /**< A sample operation failed */
    CB_ON_DEVICE_ERROR,   /**< A generic device error occurred */

    CB_NUM_OPTIONS
  };

  /*-------------------------------------------------------------------------------
  Structures
  -------------------------------------------------------------------------------*/
  /**
   * @brief Measurement type for 3-axis sensors
   */
  struct TriAxisSample
  {
    float x; /**< X-Axis sample */
    float y; /**< Y-Axis sample */
    float z; /**< Z-Axis sample */
  };

  using AccelSample = TriAxisSample;
  using GyroSample  = TriAxisSample;
  using MagSample   = TriAxisSample;


  /**
   * @brief Common sensor attribute description
   */
  struct Details
  {
    char name[ 16 ];      /**< Name of the device, usually the P/N */
    uint8_t version;      /**< Software driver version */
    uint8_t uuid;         /**< Unique identifier to distinguish between similar sensors */
    Variant type;         /**< Sensor type */
    float maxValue;       /**< Maximum value the sensor may output */
    float minValue;       /**< Minimum value the sensor may output */
    float resolution;     /**< Smallest delta the sensor can report, in base SI units */
    size_t maxSampleRate; /**< Maximum sampling rate in milliseconds */
  };

  /**
   * @brief Core container for a generic sensor sample
   */
  struct Sample
  {
    union
    {
      AccelSample accel; /**< Accelerometer */
      GyroSample gyro;   /**< Gyroscope */
      MagSample mag;     /**< Magnetometer */
    } data;

    size_t timestamp; /**< System time the sample was taken */
    Variant type;     /**< Sensor type */
    bool isValid;     /**< Data validity */

    /**
     * @brief Construct a new Sample object
     */
    Sample()
    {
      timestamp = 0;
      type      = Variant::INVALID;
      isValid   = false;
      memset( &data, 0, sizeof( data ) );
    }
  };


}    // namespace Valkyrie::Sensor

#endif /* !SENSOR_INTERFACE_TYPES_HPP */
