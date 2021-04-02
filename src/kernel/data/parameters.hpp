/********************************************************************************
 *  File Name:
 *    parameters.hpp
 *
 *  Description:
 *    Interface for accessing/storing system data
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VALKYRIE_SYSTEM_PARAMETERS_HPP
#define VALKYRIE_SYSTEM_PARAMETERS_HPP

/* Project Includes */
#include <src/kernel/data/registry_data.hpp>

namespace Valkyrie::Registry
{
  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  namespace Boot
  {
    /**
     * @brief Initializes the system registry memory
     *  This creates the RAM structures used to store the parameter data that
     *  is distributed across the system.
     *
     * @return void
     */
    void initRegistry();
  }

  /**
   * @brief Reads from the database in a thread safe way
   *
   * @param key     Which key to look up
   * @param data    Data buffer to write into
   * @param size    Size of the data buffer. Must match the sizeof() of the registered key.
   * @return true   Data is valid
   * @return false  Data is invalid
   */
  bool readSafe( const DatabaseKeys key, void *const data, const size_t size );

  /**
   * @brief Writes into the database in a thread safe way
   * @note Only simple parameters can be updated. Observables must be updated through
   *       their registered interface.
   *
   * @param key     Which key to write data into
   * @param data    Data buffer to write from
   * @param size    Bytes to write. Must match the sizeof() of the registered key.
   * @return true   The write was successfull
   * @return false  The write failed
   */
  bool writeSafe( const DatabaseKeys key, const void *const data, const size_t size );

}  // namespace Valkyrie

#endif  /* !VALKYRIE_SYSTEM_PARAMETERS_HPP */
