/********************************************************************************
 *  File Name:
 *    gyro_sensor.hpp
 *
 *  Description:
 *    Project interface for the Gyroscope
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VALKYRIE_SENSOR_GYROSCOPE_HPP
#define VALKYRIE_SENSOR_GYROSCOPE_HPP

/* STL Includes */
#include <memory>

/* Aurora Includes */
#include <Aurora/sensors>

namespace Valkyrie::Sensor::Gyro
{
  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  /**
   * @brief Initialize the Gyroscope driver
   *
   * The hardware/sim should be ready for use on exit
   */
  void initialize();

  /**
   * @brief Get the Sensor object
   *
   * @return Aurora::Sensor::ISensor_sPtr
   */
  Aurora::Sensor::ISensor_sPtr getInstance( const size_t instance );

  /*-------------------------------------------------------------------------------
  Classes
  -------------------------------------------------------------------------------*/
  class Physical : public Aurora::Sensor::Gyroscope::IGyro
  {
  public:
    Physical();
    ~Physical();

    /*-------------------------------------------------
    Base Interface
    -------------------------------------------------*/
    void setConnection( const Chimera::Peripheral::Connection &connection ) final override;
    void getDetails( Aurora::Sensor::Details &data ) final override;
    void getMeasurement( Aurora::Sensor::Sample &data ) final override;
    void enable() final override;
    void disable() final override;
    void measure() final override;

    /*-------------------------------------------------
    Gyroscope Interface
    -------------------------------------------------*/
    bool setGyroRange( const Aurora::Sensor::Gyroscope::Range range ) final override;
  };


  class Simulated : public Aurora::Sensor::Gyroscope::IGyro
  {
  public:
    Simulated();
    ~Simulated();

    /*-------------------------------------------------
    Driver Interface
    -------------------------------------------------*/
    /**
     * @brief Set up the ZeroMQ connection profile
     *
     * @param tcp_port  Which port to listen for information on
     * @param topic     Topic the data is published on
     */
    void configureZMQ( const size_t tcp_port, const std::string_view &topic );

    /*-------------------------------------------------
    Base Interface
    -------------------------------------------------*/
    void setConnection( const Chimera::Peripheral::Connection &connection ) final override;
    void getDetails( Aurora::Sensor::Details &data ) final override;
    void getMeasurement( Aurora::Sensor::Sample &data ) final override;
    void enable() final override;
    void disable() final override;
    void measure() final override;

    /*-------------------------------------------------
    Gyroscope Interface
    -------------------------------------------------*/
    bool setGyroRange( const Aurora::Sensor::Gyroscope::Range range ) final override;

  private:
#if defined( SIMULATOR )
    std::string mTopic;
    std::unique_ptr<zmq::socket_t> mRXSocket;
#endif /* SIMULATOR */
  };

}    // namespace Valkyrie::Sensor::Gyro

#endif /* !VALKYRIE_SENSOR_GYROSCOPE_HPP */
