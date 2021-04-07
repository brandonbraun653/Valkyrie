/********************************************************************************
 *  File Name:
 *    gyro_driver_sim.cpp
 *
 *  Description:
 *    Simulator driver for getting gyroscope data
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

#if defined( SIMULATOR )

namespace Valkyrie::Sensor::Gyro
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


  void Simulated::configureZMQ( const size_t tcp_port, const std::string_view &topic )
  {
    mRXSocket = std::make_unique<zmq::socket_t>( Virtual::ZMQContext, ZMQ_SUB );
    mRXSocket->connect( Virtual::buildAddress( tcp_port ) );
    mRXSocket->setsockopt( ZMQ_SUBSCRIBE, topic.data(), topic.length() );

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
    GyroSample gyro_data   = {};
    zmq::message_t message = {};

    /*-------------------------------------------------
    Grab the topic and verify it matches expectactions
    -------------------------------------------------*/
    zmq::recv_result_t result = mRXSocket->recv( message, zmq::recv_flags::dontwait );
    if ( result <= 0 )
    {
      /* No data to be had yet */
      return;
    }

    std::string rx_topic( reinterpret_cast<char *>( message.data() ) );
    if ( rx_topic.find( mTopic ) != 0 )
    {
      /* Topic doesn't match! */
      return;
    }

    /*-------------------------------------------------
    Grab the data and verify expectations
    -------------------------------------------------*/
    result = mRXSocket->recv( message, zmq::recv_flags::dontwait );
    if ( ( result <= 0 ) || ( message.size() != GyroSample_size ) )
    {
      /* No data or wrong size received */
      return;
    }

    /*-------------------------------------------------
    Decode the byte stream
    -------------------------------------------------*/
    pb_istream_t inputStream = pb_istream_from_buffer( reinterpret_cast<uint8_t *>( message.data() ), message.size() );
    bool decodeOK            = pb_decode( &inputStream, GyroSample_fields, &gyro_data );

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
      mLastMeasurement.isValid     = true;
      mLastMeasurement.data.gyro.x = gyro_data.x;
      mLastMeasurement.data.gyro.y = gyro_data.y;
      mLastMeasurement.data.gyro.z = gyro_data.z;
      mLastMeasurement.type        = Variant::GYROSCOPE;
      mLastMeasurement.timestamp   = Chimera::millis();

      /*-------------------------------------------------
      Invoke the user callback
      -------------------------------------------------*/
      mCBService_registry.call( static_cast<size_t>( Event::CB_ON_SAMPLE_SUCCESS ) );
    }
    else
    {
      mCBService_registry.call( static_cast<size_t>( Event::CB_ON_SAMPLE_FAIL ) );
      LOG_TRACE( "Gyroscope sensor read failure\r\n" );
    }
  }


  /*-------------------------------------------------
  Gyroscope Interface
  -------------------------------------------------*/
  bool Simulated::setGyroRange( const Aurora::Sensor::Gyroscope::Range range )
  {
    return false;
  }

}    // namespace Valkyrie::Sensor::Gyro

#endif /* SIMULATOR */
