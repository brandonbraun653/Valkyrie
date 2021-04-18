/********************************************************************************
 *  File Name:
 *    mag_driver_sim.cpp
 *
 *  Description:
 *    Simulator driver for getting magerometer data
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Includes */
#include <Aurora/logging>
#include <Aurora/sensors>

/* Chimera Includes */
#include <Chimera/thread>

/* Project Includes */
#include <Valkyrie/autogen>
#include <Valkyrie/sensors>
#include <Valkyrie/sim>

#if defined( SIMULATOR )

namespace Valkyrie::Sensor::Mag
{
  /*-------------------------------------------------------------------------------
  Classes
  -------------------------------------------------------------------------------*/
  Simulated::Simulated()
  {
  }


  Simulated::~Simulated()
  {
  }


  void Simulated::configureZMQ( const std::string_view &topic )
  {
    mTopic = topic;
  }


  /*-------------------------------------------------
  Base Interface
  -------------------------------------------------*/
  void Simulated::setConnection( const Chimera::Peripheral::Connection &connection )
  {
  }


  void Simulated::getDetails( Aurora::Sensor::Details &data )
  {
  }


  void Simulated::getMeasurement( Aurora::Sensor::Sample &data )
  {
    Chimera::Thread::LockGuard( *this );
    data = mLastMeasurement;
  }


  void Simulated::enable()
  {
  }


  void Simulated::disable()
  {
  }


  void Simulated::measure()
  {
    using namespace Aurora::Sensor;
    using namespace Valkyrie::Sim::Transport;

    /*-------------------------------------------------
    Input protection
    -------------------------------------------------*/
    if ( !mRXSocket )
    {
      return;
    }

    /*-------------------------------------------------
    Initialize memory buffers for receiving data
    -------------------------------------------------*/
    MagSample mag_data     = {};
    zmq::message_t message = {};

    /*-------------------------------------------------
    Grab data from the queue
    -------------------------------------------------*/
    TopicResource &tp = ZMQTopics.at( static_cast<size_t>( Registry::KEY_SIM_PORT_SENSOR_TOPIC_MAG ) );
    {
      Chimera::Thread::LockGuard( *tp.mtx );
      if( !tp.transmitType && !tp.queue->empty() )
      {
        message.copy( tp.queue->front() );
        tp.queue->pop();
      }
      else
      {
        /* No valid data yet */
        return;
      }
    }

    /*-------------------------------------------------
    Decode the byte stream
    -------------------------------------------------*/
    pb_istream_t inputStream = pb_istream_from_buffer( reinterpret_cast<uint8_t *>( message.data() ), message.size() );
    bool decodeOK            = pb_decode( &inputStream, MagSample_fields, &mag_data );

    /*-------------------------------------------------
    Handle decode result
    -------------------------------------------------*/
    if ( decodeOK )
    {
      /*-------------------------------------------------
      Validate sensor readings fall within expected range
      -------------------------------------------------*/
      // TODO

      /*-------------------------------------------------
      Update the last measurement
      -------------------------------------------------*/
      Chimera::Thread::LockGuard( *this );
      mLastMeasurement.isValid    = true;
      mLastMeasurement.data.mag.x = mag_data.x;
      mLastMeasurement.data.mag.y = mag_data.y;
      mLastMeasurement.data.mag.z = mag_data.z;
      mLastMeasurement.type       = Variant::MAGNETOMETER;
      mLastMeasurement.timestamp  = Chimera::millis();

      /*-------------------------------------------------
      Invoke the user callback
      -------------------------------------------------*/
      mCBService_registry.call( static_cast<size_t>( Event::CB_ON_SAMPLE_SUCCESS ) );
    }
    else
    {
      mCBService_registry.call( static_cast<size_t>( Event::CB_ON_SAMPLE_FAIL ) );
      LOG_TRACE( "Magnetometer sensor read failure\r\n" );
    }
  }


  /*-------------------------------------------------
  Magnetometer Interface
  -------------------------------------------------*/
  bool Simulated::setMagRange( const Aurora::Sensor::Magnetometer::Range range )
  {
    return false;
  }

}    // namespace Valkyrie::Sensor::Mag

#endif /* SIMULATOR */
