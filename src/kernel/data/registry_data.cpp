/********************************************************************************
 *  File Name:
 *    registry_data.cpp
 *
 *  Description:
 *    Interactions with the system registry
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <cstddef>
#if defined( SIMULATOR )
#include <iostream>
#include <fstream>
#include <filesystem>
#endif  /* SIMULATOR */

/* Valkyrie Includes */
#include <Valkyrie/kernel>

namespace Valkyrie::Registry
{
  /*-------------------------------------------------------------------------------
  Static Function Declarations
  -------------------------------------------------------------------------------*/
  static bool loadDataEmbedded( std::string_view &filename, uint8_t *const buffer, const size_t size );
  static bool loadDataSimulator( std::string_view &filename, uint8_t *const buffer, const size_t size );

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  bool loadData( std::string_view &filename, uint8_t *const buffer, const size_t size )
  {
    #if defined( EMBEDDED )
    return loadDataEmbedded( filename, buffer, size );
    #else
    return loadDataSimulator( filename, buffer, size );
    #endif  /* EMBEDDED */
  }

  /*-------------------------------------------------------------------------------
  Static Function Defintions
  -------------------------------------------------------------------------------*/
  static bool loadDataEmbedded( std::string_view &filename, uint8_t *const buffer, const size_t size )
  {
    #if defined( EMBEDDED )
    // TODO!
    return false;
    #else
    return false;
    #endif  /* EMBEDDED */
  }


  static bool loadDataSimulator( std::string_view &filename, uint8_t *const buffer, const size_t size )
  {
    #if defined( SIMULATOR )
    /*-------------------------------------------------
    Find the config file. For now assume that the root
    directory for all config files is hard coded.
    -------------------------------------------------*/
    auto databaseDir = std::filesystem::path{ __FILE__ }.parent_path().parent_path().parent_path() / "database";
    auto databaseFile = databaseDir / filename;

    if( !std::filesystem::exists( databaseFile ) )
    {
      return false;
    }

    std::ifstream is( databaseFile.c_str(), std::ifstream::binary );
    is.seekg( 0, is.end );
    int length = is.tellg();
    is.seekg( 0, is.beg );

    if( length > size )
    {
      is.close();
      return false;
    }

    is.read( reinterpret_cast<char *>( buffer ), length );
    is.close();
    return true;

    #else
    return false;
    #endif  /* SIMULATOR */
  }

}  // namespace Valkyrie::Registry
