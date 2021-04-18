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

/* Chimera Includes */
#include <Chimera/utility>

/* Project Includes */
#include <Valkyrie/kernel>
#include <Valkyrie/sim>


namespace Valkyrie::Registry
{
  /*-------------------------------------------------------------------------------
  Constants
  -------------------------------------------------------------------------------*/
  static constexpr size_t ObservableRange = KEY_OBSERVABLE_END - KEY_OBSERVABLE_START;


  namespace _Internal
  {
    /*-------------------------------------------------
    Database Memory Allocation
      Sized to 1MB for now, which seems sufficient.
    -------------------------------------------------*/
    Aurora::Database::RAM Database;
    static Aurora::Database::EntryStore<NUM_DATABASE_KEYS> dbEntryStore;
    static std::array<uint8_t, 1 * 1024 * 1024> dbRAM;

    /*-------------------------------------------------
    Datastore Memory Allocation
    -------------------------------------------------*/
    Aurora::Datastore::Manager Datastore;
    static Aurora::Datastore::ObservableMapStorage<ObservableRange> dsMemory;
  }    // namespace _Internal


  namespace Boot
  {
    /*-------------------------------------------------------------------------------
    Static Functions
    -------------------------------------------------------------------------------*/
    static void registerObservables();
    static void datastoreRegisterFail( const size_t id );


    /*-------------------------------------------------------------------------------
    Public Functions
    -------------------------------------------------------------------------------*/
    void initRegistry()
    {
      using namespace Aurora::Datastore;
      using namespace Aurora::Logging;
      using namespace _Internal;

      /*-------------------------------------------------
      Initialize the database, which forms the back-end
      of the datastore.
      -------------------------------------------------*/
      Database.assignCoreMemory( dbEntryStore, dbRAM.data(), dbRAM.size() );
      Database.reset();

      /*-------------------------------------------------
      Initialize the datastore
      -------------------------------------------------*/
      auto registerCallback = etl::delegate<void( size_t )>::create<datastoreRegisterFail>();

      Datastore.assignCoreMemory( &dsMemory );
      Datastore.resetRegistry();
      Datastore.registerCallback( CB_REGISTER_FAIL, registerCallback );

      LOG_TRACE( "Registry initialized\r\n" );
    }


    void loadSystemConfig()
    {
      LOG_TRACE( "Loading system configuration\r\n" );

      bool all_loaded = true;

      /*-------------------------------------------------------------------------------
      Constant data loaded from non-volatile memory
      -------------------------------------------------------------------------------*/
      /*-------------------------------------------------
      Simulator configuration
      -------------------------------------------------*/
#if defined( SIMULATOR )
      SimPortsLoader sim_ports;
      all_loaded = true;
      all_loaded &= sim_ports.registerParameters();
      all_loaded &= sim_ports.populateFromFile();
      LOG_IF_ERROR( all_loaded, "Failed to load Simulator Port config\r\n" );
#endif /* SIMULATOR */

      /*-------------------------------------------------
      Sensor measurement timing
      -------------------------------------------------*/
      SensorTimingLoader sensor_timing;
      all_loaded = true;
      all_loaded &= sensor_timing.registerParameters();
      all_loaded &= sensor_timing.populateFromFile();
      LOG_IF_ERROR( all_loaded, "Failed to load Sensor Timing config\r\n" );

      /*-------------------------------------------------------------------------------
      Observable data that changes at runtime and could be used to notify other parts
      of the system of events.
      -------------------------------------------------------------------------------*/
      registerObservables();
    }

    /*-------------------------------------------------------------------------------
    Static Functions
    -------------------------------------------------------------------------------*/
    /**
     *  Allocates memory in the datastore for all system observables
     *  @return void
     */
    static void registerObservables()
    {
      /*-------------------------------------------------
      Grab the pointer to each statically declared obser-
      vable parameter and register it with the datastore.
      -------------------------------------------------*/
      for ( size_t x = 0; x < ARRAY_COUNT( ObservableList ); x++ )
      {
        bool error = _Internal::Datastore.registerObservable( ObservableList[ x ], &_Internal::Database );
        LOG_IF_ERROR( error, "Failed to register observable %d\r\n", x );
      }
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

  }    // namespace Boot


  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
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
    if ( ( KEY_SIMPLE_START <= key ) && ( key < KEY_SIMPLE_END ) && ( size == _Internal::Database.size( key ) ) )
    {
      return _Internal::Database.read( key, data );
    }
    else if ( ( KEY_OBSERVABLE_START <= key ) && ( key < KEY_OBSERVABLE_END ) )
    {
      return _Internal::Datastore.readDataSafe( key, data, size );
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
    if ( ( KEY_SIMPLE_START <= key ) && ( key < KEY_SIMPLE_END ) && ( size == _Internal::Database.size( key ) ) )
    {
      return _Internal::Database.write( key, data );
    }
    else
    {
      return false;
    }
  }

}    // namespace Valkyrie::Registry
