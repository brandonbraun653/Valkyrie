/********************************************************************************
 *  File Name:
 *    logger.hpp
 *
 *  Description:
 *    Logger interface for the project
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VALKYRIE_SYSTEM_LOGGER_HPP
#define VALKYRIE_SYSTEM_LOGGER_HPP


namespace Valkyrie::Log
{
  namespace Boot
  {
    /**
     * @brief Initializes the project loggers
     */
    void initLoggers();
  }
}  // namespace Valkyrie::Log

#endif  /* !VALKYRIE_SYSTEM_LOGGER_HPP */
