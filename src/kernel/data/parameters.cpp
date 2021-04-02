/********************************************************************************
 *  File Name:
 *    parameters.cpp
 *
 *  Description:
 *    Data parameter implementation
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Includes */
#include <Aurora/database>
#include <Aurora/datastore>
#include <Aurora/logging>

/* Project Includes */
#include <Valkyrie/kernel>


namespace Valkyrie::Registry
{
  /*-------------------------------------------------------------------------------
  Constants
  -------------------------------------------------------------------------------*/
  static constexpr size_t ObservableRange = KEY_OBSERVABLE_END - KEY_OBSERVABLE_START;

  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
  /*-------------------------------------------------
  Database Memory Allocation
    Sized to 1MB for now, which seems sufficient.
  -------------------------------------------------*/
  static Aurora::Database::RAM Database;
  static Aurora::Database::EntryStore<NUM_DATABASE_KEYS> dbEntryStore;
  static std::array<uint8_t, 1 * 1024 * 1024> dbRAM;

  /*-------------------------------------------------
  Datastore Memory Allocation
  -------------------------------------------------*/
  static Aurora::Datastore::Manager Datastore;
  static Aurora::Datastore::ObservableMapStorage<ObservableRange> dsMemory;


  /*-------------------------------------------------------------------------------
  Static Functions
  -------------------------------------------------------------------------------*/
  static void registerDatabaseKeys();
  static void registerObservables();
  static void datastoreRegisterFail( const size_t id );

  namespace Boot
  {
    void initRegistry()
    {
      using namespace Aurora::Datastore;
      using namespace Aurora::Logging;

      /*-------------------------------------------------
      Initialize the database, which forms the back-end
      of the datastore.
      -------------------------------------------------*/
      Database.assignCoreMemory( dbEntryStore, dbRAM.data(), dbRAM.size() );
      Database.reset();
      registerDatabaseKeys();

      /*-------------------------------------------------
      Initialize the datastore
      -------------------------------------------------*/
      auto registerCallback = etl::delegate<void( size_t )>::create<datastoreRegisterFail>();

      Datastore.assignCoreMemory( &dsMemory );
      Datastore.resetRegistry();
      Datastore.registerCallback( CB_REGISTER_FAIL, registerCallback );
      registerObservables();

      LOG_TRACE( "Registry initialized\r\n" );
    }

  }    // namespace Boot


  bool readSafe( const DatabaseKeys key, void *const data, const size_t size )
  {
    /*-------------------------------------------------
    Input protection
    -------------------------------------------------*/
    if ( !data || !size || !( key < NUM_DATABASE_KEYS ) )
    {
      return false;
    }

    /*-------------------------------------------------
    Select the proper interface to read from
    -------------------------------------------------*/
    if ( ( KEY_SIMPLE_START <= key ) && ( key < KEY_SIMPLE_END ) && ( size == Database.size( key ) ) )
    {
      return Database.read( key, data );
    }
    else if ( ( KEY_OBSERVABLE_START <= key ) && ( key < KEY_OBSERVABLE_END ) )
    {
      return Datastore.readDataSafe( key, data, size );
    }
    else
    {
      return false;
    }
  }


  bool writeSafe( const DatabaseKeys key, const void *const data, const size_t size )
  {
    /*-------------------------------------------------
    Input protection
    -------------------------------------------------*/
    if ( !data || !size || !( key < NUM_DATABASE_KEYS ) )
    {
      return false;
    }

    /*-------------------------------------------------
    Select the proper interface to write. Observable
    registry key types cannot be directly written to.
    -------------------------------------------------*/
    if ( ( KEY_SIMPLE_START <= key ) && ( key < KEY_SIMPLE_END ) && ( size == Database.size( key ) ) )
    {
      return Database.write( key, data );
    }
    else
    {
      return false;
    }
  }


  /*-------------------------------------------------------------------------------
  Static Functions
  -------------------------------------------------------------------------------*/
  /**
   *  Allocates memory in the database for all system parameters
   *  @return void
   */
  static void registerDatabaseKeys()
  {
    using namespace Aurora::Database;

    /*-------------------------------------------------
    Parameter sizing information
    -------------------------------------------------*/
    union ParamData
    {
      uint32_t boot_count;
    } pData;

    /*-------------------------------------------------
    Register all known parameters
    -------------------------------------------------*/
    for ( size_t x = KEY_SIMPLE_START; x < KEY_SIMPLE_END; x++ )
    {
      Chimera::Status_t result = Chimera::Status::OK;
      switch ( x )
      {
        case KEY_BOOT_COUNT:
          pData.boot_count = 0;
          result           = Database.insert( x, &pData.boot_count, sizeof( ParamData::boot_count ), MemAccess::MEM_RW );
          break;

        default:
          // A parameter was forgotten to be registered
          LOG_ERROR( "Parameter %d failed registration\r\n", x );
          break;
      }

      LOG_IF_ERROR( result == Chimera::Status::OK, "Database insertion failed on id %d\r\n", x );
    }
  }


  /**
   *  Allocates memory in the datastore for all system observables
   *  @return void
   */
  static void registerObservables()
  {
    // for ( size_t x = 0; x < ARRAY_COUNT( ObservableList ); x++ )
    // {
    //   LOG_IF_ERROR( Datastore.registerObservable( *ObservableList[ x ] ), "Failed to register observable %d\r\n", x );
    // }
  }


  /**
   *  Callback for logging when an observable parameter fails
   *  to register with the system
   *
   *  @param[in]  id      Which ID failed
   *  @return void
   */
  static void datastoreRegisterFail( const size_t id )
  {
    LOG_ERROR( "Failed to register observable %d\r\n", id );
  }


}    // namespace Valkyrie
