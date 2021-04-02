/********************************************************************************
 *  File Name:
 *    sys_init.cpp
 *
 *  Description:
 *    System init sequences for bootup
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Logging */
#include <Aurora/logging>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/thread>

/* Valkyrie Includes */
#include <Valkyrie/debug>
#include <Valkyrie/kernel>

// Testing only
#include "zmq.hpp"
#include "msgpack.hpp"

#include "pb.h"
#include "pb_decode.h"
#include "ahrs.pb.h"


namespace Valkyrie::Boot
{
  /**
   * @brief A testing thread for the sim
   *
   * @param unused
   */
  static void HelloWorld( void *unused )
  {
    LOG_INFO( "Booting system\r\n" );

    std::string_view topic = "gyro";

    zmq::context_t context(1);
    zmq::socket_t subscriber( context, ZMQ_SUB );
    subscriber.connect("tcp://127.0.0.1:50024");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, topic.data(), topic.length() );

    std::array<uint8_t, 100> rx_data;
    std::array<char, 20> rx_topic;
    rx_data.fill( 0 );
    rx_topic.fill( 0 );

    while ( true )
    {
      zmq::message_t update;
      subscriber.recv( &update );

      memcpy( rx_topic.data(), update.data(), update.size() );
      if( strcmp( rx_topic.data(), topic.data() ) == 0 )
      {
        subscriber.recv( &update );
        memcpy( rx_data.data(), update.data(), update.size() );
        pb_istream_t input = pb_istream_from_buffer( rx_data.data(), update.size() );


        GyroSample gyro_data = {};
        auto result = pb_decode( &input, GyroSample_fields, &gyro_data );
        LOG_TRACE( "Got Gyro -> x:%1.4f\ty:%1.4f\tz:%1.4f\r\n", gyro_data.x, gyro_data.y, gyro_data.z );

        //
        // msgpack::object_handle oh = msgpack::unpack( rx_data.data(), update.size() );
        // msgpack::object deserialized = oh.get();
        // float my_float = deserialized.via.f64;
        // LOG_TRACE( "gyro_x: %1.4f\r\n", my_float );
      }

      Chimera::delayMilliseconds( 1000 );
      rx_data.fill(0);
      rx_topic.fill(0);
    }
  }

  void sysPowerUp()
  {
    /*-------------------------------------------------
    Power up the debug system
    -------------------------------------------------*/
    Log::Boot::initLoggers();

    /*-------------------------------------------------
    Power up the database/registry system
    -------------------------------------------------*/
    Registry::Boot::initRegistry();
  }

  void createTasks()
  {
    using namespace Chimera::Thread;

    /*-------------------------------------------------
    Just for testing, create the hello world thread
    -------------------------------------------------*/
    TaskConfig cfg;
    cfg.function.callable.pointer = HelloWorld;
    cfg.function.type             = FunctorType::C_STYLE;
    cfg.name                      = "HelloWorld";
    cfg.priority                  = Priority::LEVEL_3;
    cfg.stackWords                = 1024;
    cfg.arg                       = nullptr;
    cfg.type                      = TaskInitType::DYNAMIC;

    Task hw;
    hw.create( cfg );
    hw.start();
  }

}    // namespace Valkyrie::Boot
