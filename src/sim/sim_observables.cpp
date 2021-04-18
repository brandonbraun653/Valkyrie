/********************************************************************************
 *  File Name:
 *    sim_observables.cpp
 *
 *  Description:
 *    Observable declarations for the simulator
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#if defined( SIMULATOR )

/* Valkyrie Include */
#include <Valkyrie/kernel>
#include <Valkyrie/sim>

namespace Valkyrie::Registry
{
  /*-------------------------------------------------------------------------------
  Sim Connected Parameter
  -------------------------------------------------------------------------------*/
  Observable_SimConnected Param_SimConnected;
  void Observable_SimConnected::initialize()
  {
    basicInit();
  }


  void Observable_SimConnected::update()
  {
    /*-------------------------------------------------
    The message is received if it exists in the queue
    -------------------------------------------------*/
    zmq::message_t message = {};
    if ( !Valkyrie::Sim::Transport::receive( Registry::KEY_SIM_PORT_TX_SIM_TOPIC_HEARTBEAT, message ) )
    {
      /* No valid data yet */
      return;
    }

    /*-------------------------------------------------
    No need to deserialize the data
    -------------------------------------------------*/
    bool connected = true;
    getDatabase()->write( this->key(), &connected );
    notify_observers( &connected );
  }


  void Observable_SimConnected::onTimeout()
  {
    /*-------------------------------------------------
    Invalidate the data
    -------------------------------------------------*/
    bool connected = false;
    getDatabase()->write( this->key(), &connected );
    notify_observers( &connected );
  }


  bool Observable_SimConnected::validate( const void *const data, const size_t size ) const
  {
    if ( !data || size != sizeof( bool ) )
    {
      return false;
    }

    return *reinterpret_cast<const bool *const>( data );
  }

}    // namespace Valkyrie::Registry

#endif /* SIMULATOR */
