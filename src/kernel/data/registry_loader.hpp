/********************************************************************************
 *  File Name:
 *    registry_loader.hpp
 *
 *  Description:
 *    Interface for loading registry data into the system
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VALKYRIE_REGISTRY_LOADER_INTF_HPP
#define VALKYRIE_REGISTRY_LOADER_INTF_HPP

/* STL Includes */
#include <string_view>

namespace Valkyrie::Registry
{
  /*-------------------------------------------------------------------------------
  Classes
  -------------------------------------------------------------------------------*/
  /**
   * @brief Interface class for initializing system parameters
   */
  class ILoader
  {
  public:
    virtual ~ILoader() = default;

    /**
     * @brief Registers paramater keys with the system registry
     *
     * @return true     All keys registered
     * @return false    Something went wrong
     */
    virtual bool registerParameters() = 0;

    /**
     * @brief Updates registered keys from a file
     *
     * @return true     All keys updated
     * @return false    Something went wrong
     */
    virtual bool populateFromFile() = 0;
  };


  class SensorTimingLoader : public ILoader
  {
  public:
    bool registerParameters() final override;
    bool populateFromFile() final override;
  };
}  // namespace Valkyrie::Registry

#endif  /* !VALKYRIE_REGISTRY_LOADER_INTF_HPP */
