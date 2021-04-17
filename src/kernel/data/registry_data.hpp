/********************************************************************************
 *  File Name:
 *    registry_data.hpp
 *
 *  Description:
 *    Declarations for the various data that is stored in the system registry
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VALKYRIE_REGISTRY_DATA_HPP
#define VALKYRIE_REGISTRY_DATA_HPP

/* Aurora Includes */
#include <Aurora/database>
#include <Aurora/datastore>

namespace Valkyrie::Registry
{
  /*-------------------------------------------------------------------------------
  Constants
  -------------------------------------------------------------------------------*/
  static constexpr size_t DFLT_OBSERVERS = 5; /**< Number of observers for parameters */

  /*-------------------------------------------------------------------------------
  Enumerations
  -------------------------------------------------------------------------------*/
  enum DatabaseKeys : Aurora::Database::Key
  {
    /*-------------------------------------------------------------------------------
    Simulator Data
    -------------------------------------------------------------------------------*/
    /*-------------------------------------------------
    Port Configuration
    -------------------------------------------------*/
#if defined( SIMULATOR )
    KEY_SIM_PORT_START,
    KEY_SIM_PORT_SENSOR = KEY_SIM_PORT_START,    /**< Simulated sensor data from drone physics */
    KEY_SIM_PORT_SYS_CTRL,  /**< Control inputs from flight software to sim */
    KEY_SIM_PORT_USR_INPUT, /**< Various user input data to the sim */
    KEY_SIM_PORT_TX_SIM,    /**< Port the simulator transmits on to the flight software */
    KEY_SIM_PORT_RX_SIM,    /**< Port the simulator listens on for incoming data */
    KEY_SIM_PORT_END,
#endif  /* SIMULATOR */

    /*-------------------------------------------------
    Topic Configuration
    -------------------------------------------------*/
#if defined( SIMULATOR )
    KEY_SIM_TOPIC_START,
    KEY_SIM_PORT_SENSOR_TOPIC_ACCEL = KEY_SIM_TOPIC_START,
    KEY_SIM_PORT_SENSOR_TOPIC_GYRO,
    KEY_SIM_PORT_SENSOR_TOPIC_MAG,
    KEY_SIM_PORT_SYS_CTRL_TOPIC_MOTOR,
    KEY_SIM_PORT_USR_INPUT_TOPIC_SET_POINT,
    KEY_SIM_PORT_TX_SIM_TOPIC_HEARTBEAT,
    KEY_SIM_PORT_RX_SIM_TOPIC_HEARTBEAT,
    KEY_SIM_TOPIC_END,
#endif  /* SIMULATOR */

    /*-------------------------------------------------------------------------------
    Simple Data
    -------------------------------------------------------------------------------*/
    KEY_SIMPLE_START,
    KEY_BOOT_COUNT = KEY_SIMPLE_START,

    /*-------------------------------------------------
    Sensor Sample Rates
    -------------------------------------------------*/
    KEY_SAMPLE_RATE_ACCEL,
    KEY_SAMPLE_RATE_GYRO,
    KEY_SAMPLE_RATE_MAG,
    KEY_SAMPLE_RATE_GPS,

    /*-------------------------------------------------
    Sensor Measurement Data
    -------------------------------------------------*/
    KEY_SENSOR_DATA_ACCEL,
    KEY_SENSOR_DATA_GYRO,
    KEY_SENSOR_DATA_MAG,

    /*-------------------------------------------------------------------------------
    Observable Data
    -------------------------------------------------------------------------------*/
    KEY_OBSERVABLE_START,
    KEY_BUTTON_UP = KEY_OBSERVABLE_START,
    KEY_BUTTON_DOWN,

    /*-------------------------------------------------
    Miscellaneous
    -------------------------------------------------*/
    NUM_DATABASE_KEYS,
    KEY_INVALID,

    /*-------------------------------------------------
    Aliases
    -------------------------------------------------*/
    KEY_OBSERVABLE_END  = NUM_DATABASE_KEYS,
    KEY_SIMPLE_END = KEY_OBSERVABLE_START,

    /*-------------------------------------------------
    Configuration
    -------------------------------------------------*/
    sim_TOPIC_STR_SIZE = 32,
  };

  /*-------------------------------------------------------------------------------
  Observable Data Class Declarations
  -------------------------------------------------------------------------------*/
  // /* clang-format off */
  // DECLARE_OBSERVABLE( ButtonDown, uint32_t, KEY_BUTTON_DOWN,  DFLT_OBSERVERS, 50, 100 );
  // DECLARE_OBSERVABLE( ButtonUp,   uint32_t, KEY_BUTTON_UP,    DFLT_OBSERVERS, 50, 100 );
  // /* clang-format on */

  // static Aurora::Datastore::IObservableAttr *const ObservableList[] = {
  //   OBSERVABLE_PTR( ButtonDown ),
  //   OBSERVABLE_PTR( ButtonUp ),
  // };

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  /**
   * @brief Loads an entire registry file into the given buffer
   *
   * @param filename    The file being loaded
   * @param buffer      Where to write the data into
   * @param size        Size of the output buffer
   * @return true       Load succeeded
   * @return false      Load failed
   */
  bool loadData( std::string_view &filename, uint8_t *const buffer, const size_t size );
}  // namespace Valkyrie

#endif  /* !VALKYRIE_REGISTRY_DATA_HPP */
