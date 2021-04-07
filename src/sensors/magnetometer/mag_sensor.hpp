/********************************************************************************
 *  File Name:
 *    mag_sensor.hpp
 *
 *  Description:
 *    Project interface for the Magnetometer
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VALKYRIE_SENSOR_MAGNETOMETER_HPP
#define VALKYRIE_SENSOR_MAGNETOMETER_HPP

/* STL Includes */
#include <memory>

/* Aurora Includes */
#include <Aurora/sensors>

namespace Valkyrie::Sensor::Mag
{
  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  /**
   * @brief Initialize the Magnetometer driver
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
  class Physical : public Aurora::Sensor::Magnetometer::IMag
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
    Magnetometer Interface
    -------------------------------------------------*/
    bool setMagRange( const Aurora::Sensor::Magnetometer::Range range ) final override;
  };


  class Simulated : public Aurora::Sensor::Magnetometer::IMag
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
    Magnetometer Interface
    -------------------------------------------------*/
    bool setMagRange( const Aurora::Sensor::Magnetometer::Range range ) final override;

  private:
#if defined( SIMULATOR )
    std::string mTopic;
    std::unique_ptr<zmq::socket_t> mRXSocket;
#endif /* SIMULATOR */
  };

}    // namespace Valkyrie::Sensor::Accel

#endif /* !VALKYRIE_SENSOR_MAGNETOMETER_HPP */
