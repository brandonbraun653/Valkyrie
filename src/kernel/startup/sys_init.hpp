/********************************************************************************
 *  File Name:
 *    sys_init.hpp
 *
 *  Description:
 *    Task initialization interface
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VALKYRIE_STARTUP_SYSTEM_INIT_HPP
#define VALKYRIE_STARTUP_SYSTEM_INIT_HPP

namespace Valkyrie::Boot
{
  /**
   * @brief Powers up system aspects that don't require an RTOS
   */
  void sysPowerUp();

  /**
   * @brief Creates system tasks for Valkyrie to boot
   * Initializes the background thread, which will boot other
   * threads once the tasking system has started.
   */
  void createBackgroundThread();
}    // namespace Valkyrie::Boot

#endif /* !VALKYRIE_STARTUP_SYSTEM_INIT_HPP */
