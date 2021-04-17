/********************************************************************************
 *  File Name:
 *    listing.hpp
 *
 *  Description:
 *    List out all the threads in use with the project
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VALKYRIE_THREAD_LISTING_HPP
#define VALKYRIE_THREAD_LISTING_HPP

/* Chimera Includes */
#include <Chimera/thread>

namespace Valkyrie::Thread
{
  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  /**
   * @brief Starts up the system threads
   */
  void CreateThreads();

  /*-------------------------------------------------------------------------------
  Background Thread: Idle processing and low priority tasks
  -------------------------------------------------------------------------------*/
  namespace Background
  {
    static const std::string_view Name = "Bkgd";
    static constexpr size_t StackDepth = STACK_BYTES( 1024 );

    /**
     * @brief Entry for the background thread
     *
     * @param arg   Unused
     */
    void main( void *arg );
  }    // namespace Background

  /*-------------------------------------------------------------------------------
  Hardware Manager: Performs IO access to system hardware
  -------------------------------------------------------------------------------*/
  namespace HardwareManager
  {
    static const std::string_view Name = "HWMgr";
    static constexpr size_t Period     = 5;
    static constexpr size_t StackDepth = STACK_BYTES( 1024 );

    /**
     * @brief Entry for the background thread
     *
     * @param arg   Unused
     */
    void main( void *arg );
  }    // namespace HardwareManager


  /*-------------------------------------------------------------------------------
  System Monitor: Watches the system state, like a more complicated watchdog.
  -------------------------------------------------------------------------------*/
  namespace SystemMonitor
  {
    static const std::string_view Name = "SYSMon";
    static constexpr size_t StackDepth = STACK_BYTES( 1024 );

    /**
     * @brief Entry for the background thread
     *
     * @param arg   Unused
     */
    void main( void *arg );
  }    // namespace SystemMonitor

#if defined( SIMULATOR )
  /*-------------------------------------------------------------------------------
  Simulator Thread: Pumps RX/TX data through the simulator ports
  -------------------------------------------------------------------------------*/
  namespace Sim
  {
    static const std::string_view Name = "SimPump";
    static constexpr size_t Period     = 5;
    static constexpr size_t StackDepth = STACK_BYTES( 10 * 1024 );

    /**
     * @brief Entry for the background thread
     *
     * @param arg   Unused
     */
    void main( void *arg );
  }    // namespace Sim
#endif /* SIMULATOR */

}    // namespace Valkyrie::Thread

#endif /* !VALKYRIE_THREAD_LISTING_HPP */
