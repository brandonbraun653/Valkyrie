/********************************************************************************
 *  File Name:
 *    sensor_intf.hpp
 *
 *  Description:
 *    Describes the base class that is used for all sensors
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VIRTUAL_SENSOR_INTERFACE_HPP
#define VIRTUAL_SENSOR_INTERFACE_HPP

/* Chimera Includes */
#include <Chimera/callback>
#include <Chimera/thread>

/* Project Includes */
#include <src/sensors/sensor_types.hpp>

namespace Valkyrie::Sensor
{
  /**
   * @brief Core class that all sensor types must inherit from
   *
   *  In addition to a standard interface to initialize a device and acquire
   *  measurement data, this class supports event callbacks and locks for
   *  thread safe access.
   */
  class IBase : public Chimera::Callback::DelegateService<IBase, Event>, public Chimera::Thread::Lockable<IBase>
  {
  public:
    virtual ~IBase() = default;

    /**
     * @brief Get the sensor description details
     *
     * @param data      Structure to fill with details
     * @return Details
     */
    virtual void getDetails( Details &data ) = 0;

    /**
     * @brief Enable the sensor
     * This prepares the sensor for all IO operations and places it
     * in an idle state.
     */
    virtual void enable() = 0;

    /**
     * @brief Disable the sensor
     * This disables the sensor, rendering it ineffective
     */
    virtual void disable() = 0;

    /**
     * @brief Instruct the device to take a measurement
     *
     * @note  The measurement is not returned in this function to allow
     *        temporal and spacial separation of reading the data. One
     *        thread may periodically take measurements and others may
     *        consume the data.
     */
    virtual void measure() = 0;

    /**
     * @brief Grab the last successful measurement from the device
     *
     * @param data      Structure to pack with the sampled data
     * @return true     The measurement completed successfully
     * @return false    The measurement failed
     */
    virtual void getMeasurement( Sample &data ) = 0;

  protected:
    Sample mLastMeasurement; /**< Cache for storing the last taken measurement */
  };
}    // namespace Valkyrie::Sensor

#endif /* !VIRTUAL_SENSOR_INTERFACE_HPP */
