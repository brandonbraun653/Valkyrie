/********************************************************************************
 *  File Name:
 *    sensor_intf.hpp
 *
 *  Description:
 *    High level sensor module interface
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VALKYRIE_SENSOR_INTERFACE_HPP
#define VALKYRIE_SENSOR_INTERFACE_HPP


namespace Valkyrie::Sensor
{
  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  /**
   * @brief Initialize the IMU drivers
   */
  void initIMU();

  /**
   * @brief Sample the IMU hardware to obtain a new measurement
   */
  void processIMU();
}  // namespace Valkyrie::Sensor

#endif  /* !VALKYRIE_SENSOR_INTERFACE_HPP */
