/********************************************************************************
 *  File Name:
 *    virtual_sensor.hpp
 *
 *  Description:
 *    Resources for interfacing with virtual sensors
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VALKYRIE_SENSOR_VIRTUAL_HPP
#define VALKYRIE_SENSOR_VIRTUAL_HPP

#if defined( SIMULATOR )

/* STL Includes */
#include <cstddef>
#include <string>

/* ZMQ Includes */
#include <zmq.hpp>

namespace Valkyrie::Sensor::Virtual
{
  /*-------------------------------------------------------------------------------
  Constants
  -------------------------------------------------------------------------------*/
  static constexpr size_t MAX_TOPIC_LEN = 32;

  /*-------------------------------------------------------------------------------
  Public Data
  -------------------------------------------------------------------------------*/
  extern zmq::context_t ZMQContext;

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  /**
   * @brief Initialize the ZMQ transport layer
   *
   * @param threads   Number of threads to use
   */
  void initTransport( const size_t threads );

  /**
   * @brief Builds the ZMQ address to connect to
   *
   * @param tcp_port      Which TCP port is used
   * @return std::string
   */
  std::string buildAddress( const size_t tcp_port );

}    // namespace Valkyrie::Sensor::Virtual

#endif /* !VALKYRIE_SENSOR_VIRTUAL_HPP */
#endif /* SIMULATOR */
