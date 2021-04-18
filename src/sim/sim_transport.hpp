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
#include <queue>

/* Valkyrie Includes */
#include <Valkyrie/kernel>

/* ZMQ Includes */
#include <zmq.hpp>

/* ETL Includes */
#include <etl/queue.h>
#include <etl/map.h>

namespace Valkyrie::Sim::Transport
{
  /*-------------------------------------------------------------------------------
  Forward Declarations
  -------------------------------------------------------------------------------*/
  struct TopicResource;

  /*-------------------------------------------------------------------------------
  Constants
  -------------------------------------------------------------------------------*/
  static constexpr size_t MAX_TOPIC_LEN  = 32;
  static constexpr size_t MAX_QUEUE_ELEM = 100;
  static constexpr size_t NUM_SOCKETS    = Registry::KEY_SIM_PORT_END - Registry::KEY_SIM_PORT_START;
  static constexpr size_t NUM_TOPICS     = Registry::KEY_SIM_TOPIC_END - Registry::KEY_SIM_TOPIC_START;

  /*-------------------------------------------------------------------------------
  Aliases
  -------------------------------------------------------------------------------*/
  using MessageQueue = std::queue<zmq::message_t>;
  using MappedTopic  = etl::map<size_t, TopicResource, NUM_TOPICS>;
  using MappedSocket = etl::map<size_t, std::shared_ptr<zmq::socket_t>, NUM_SOCKETS>;

  /*-------------------------------------------------------------------------------
  Types
  -------------------------------------------------------------------------------*/
  struct TopicResource
  {
    bool transmitType;
    MessageQueue *queue;
    std::shared_ptr<zmq::socket_t> socket;
    Chimera::Thread::RecursiveMutex *mtx;
  };

  /*-------------------------------------------------------------------------------
  Public Data
  -------------------------------------------------------------------------------*/
  extern zmq::context_t ZMQContext; /**< ZMQ context for the entire simulation */
  extern MappedSocket ZMQSockets;   /**< Sockets associated with each topic */
  extern MappedTopic ZMQTopics;


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
