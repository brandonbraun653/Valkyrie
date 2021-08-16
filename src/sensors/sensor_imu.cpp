/********************************************************************************
 *  File Name:
 *    sensor_imu.cpp
 *
 *  Description:
 *    Interface driver for the system sensors
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Includes */
#include <Aurora/logging>
#include <Aurora/sensors>
#include <Aurora/utility>

/* Valkyrie Includes */
#include <Valkyrie/kernel>
#include <Valkyrie/sensors>

namespace Valkyrie::Sensor
{
  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
  static Aurora::Sensor::ISensor_sPtr accel;
  static Aurora::Utility::PeriodicTimeout accelTimeout;

  static Aurora::Sensor::ISensor_sPtr gyro;
  static Aurora::Utility::PeriodicTimeout gyroTimeout;

  static Aurora::Sensor::ISensor_sPtr mag;
  static Aurora::Utility::PeriodicTimeout magTimeout;

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void initIMU()
  {
    /*-------------------------------------------------
    Power up the accelerometer
    -------------------------------------------------*/
    Valkyrie::Sensor::Accel::initialize();
    accel = Valkyrie::Sensor::Accel::getInstance( 0 );

    size_t accelRate = std::numeric_limits<size_t>::max();
    Registry::readSafe( Registry::KEY_SAMPLE_RATE_ACCEL, &accelRate, sizeof( accelRate ) );
    accelTimeout.setTimeout( accelRate );

    Registry::_Internal::Database.insert( Registry::KEY_SENSOR_DATA_ACCEL, sizeof( Aurora::Sensor::TriAxisSample ) );

    /*-------------------------------------------------
    Power up the gyroscope
    -------------------------------------------------*/
    Valkyrie::Sensor::Gyro::initialize();
    gyro = Valkyrie::Sensor::Gyro::getInstance( 0 );

    size_t gyroRate = std::numeric_limits<size_t>::max();
    Registry::readSafe( Registry::KEY_SAMPLE_RATE_GYRO, &gyroRate, sizeof( gyroRate ) );
    gyroTimeout.setTimeout( gyroRate );

    Registry::_Internal::Database.insert( Registry::KEY_SENSOR_DATA_GYRO, sizeof( Aurora::Sensor::TriAxisSample ) );


    /*-------------------------------------------------
    Power up the magnetometer
    -------------------------------------------------*/
    Valkyrie::Sensor::Mag::initialize();
    mag = Valkyrie::Sensor::Mag::getInstance( 0 );

    size_t magRate = std::numeric_limits<size_t>::max();
    Registry::readSafe( Registry::KEY_SAMPLE_RATE_MAG, &magRate, sizeof( magRate ) );
    magTimeout.setTimeout( magRate );

    Registry::_Internal::Database.insert( Registry::KEY_SENSOR_DATA_MAG, sizeof( Aurora::Sensor::TriAxisSample ) );
  }


  void processIMU()
  {
    using namespace Aurora::Sensor;

    /*-------------------------------------------------
    Function data cache
    -------------------------------------------------*/
    Sample reading = {};
    bool updateOk  = true;

    /*-------------------------------------------------
    Temporary protections until sensors instances are
    supported on HW.
    -------------------------------------------------*/
    if( !accel || !gyro || !mag )
    {
      return;
    }

    /*-------------------------------------------------
    Process the accelerometer
    -------------------------------------------------*/
    if ( accelTimeout.expired() )
    {
      accelTimeout.refresh();
      accel->measure();
      accel->getMeasurement( reading );

      if ( reading.isValid )
      {
        updateOk &= Registry::writeSafe( Registry::KEY_SENSOR_DATA_ACCEL, &reading.data.accel, sizeof( Sample::data.accel ) );
      }
    }

    /*-------------------------------------------------
    Process the gyroscope
    -------------------------------------------------*/
    if ( gyroTimeout.expired() )
    {
      gyroTimeout.refresh();
      gyro->measure();
      gyro->getMeasurement( reading );

      if ( reading.isValid )
      {
        updateOk &= Registry::writeSafe( Registry::KEY_SENSOR_DATA_GYRO, &reading.data.gyro, sizeof( Sample::data.gyro ) );
      }
    }

    /*-------------------------------------------------
    Process the magnetometer
    -------------------------------------------------*/
    if ( magTimeout.expired() )
    {
      magTimeout.refresh();
      mag->measure();
      mag->getMeasurement( reading );

      if ( reading.isValid )
      {
        updateOk &= Registry::writeSafe( Registry::KEY_SENSOR_DATA_MAG, &reading.data.mag, sizeof( Sample::data.mag ) );
      }
    }

    /*-------------------------------------------------
    Make sure all updates went ok
    -------------------------------------------------*/
    LOG_ERROR_IF( !updateOk, "IMU update failed\r\n" );
  }

}    // namespace Valkyrie::Sensor
