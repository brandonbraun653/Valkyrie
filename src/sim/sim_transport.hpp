/********************************************************************************
 *  File Name:
 *    sim_transport.hpp
 *
 *  Description:
 *    Resources for interfacing remote connections over ZMQ
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VALKYRIE_SIM_TRANSPORT_HPP
#define VALKYRIE_SIM_TRANSPORT_HPP

#if defined( SIMULATOR )

/* STL Includes */
#include <cstddef>
#include <string>

/* Valkyrie Includes */
#include <Valkyrie/kernel>

/* ZMQ Includes */
#include <zmq.hpp>

namespace Valkyrie::Sim::Transport
{
  /*-------------------------------------------------------------------------------
  Constants
  -------------------------------------------------------------------------------*/
  static constexpr size_t MAX_TOPIC_LEN = 32;

  /*-------------------------------------------------------------------------------
  Public Data
  -------------------------------------------------------------------------------*/
  /**
   * @brief ZMQ context for the entire simulation
   */
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
   * @brief Registers topics that are used for transporting data around
   */
  void registerTopics();

  /**
   * @brief Builds the ZMQ address to connect to
   *
   * @param tcp_port      Which TCP port is used
   * @return std::string
   */
  std::string buildAddress( const size_t tcp_port );

  /**
   * @brief Enques a message to send through the transport layer
   *
   * @param topic   Which topic to send the message on
   * @param msg     Raw data to send
   * @return true   Data was successfully queued
   * @return false  Could not queue the data
   */
  bool transmit( Registry::DatabaseKeys topic, zmq::message_t &msg );

  /**
   * @brief Receives a message from the transport layer
   *
   * @param topic   Which topic to receive from
   * @param msg     Where to place the received message data
   * @return true   A message existed and it was retrieved successfully
   * @return false  No message exists or it was failed to be retrieved
   */
  bool receive( Registry::DatabaseKeys topic, zmq::message_t &msg );



}    // namespace Valkyrie::Sim::Transport

#endif /* !VALKYRIE_SIM_TRANSPORT_HPP */
#endif /* SIMULATOR */
