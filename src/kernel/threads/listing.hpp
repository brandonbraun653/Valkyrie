/********************************************************************************
 *  File Name:
 *    listing.hpp
 *
 *  Description:
 *    List out all the threads in use with the project
 *
 *  2021 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef VALKYRIE_THREAD_LISTING_HPP
#define VALKYRIE_THREAD_LISTING_HPP

/* Chimera Includes */
#include <Chimera/thread>

namespace Valkyrie::Thread
{
  /*-------------------------------------------------------------------------------
  Threads:

  - System power up (background thread)
    - This thread should start all other threads
  - Sensor measurement
    - Read sensors at various periods
    - Pushes data into the system database
  - Health Monitor
    - Reads system state and ensures it's all a-ok

  -------------------------------------------------------------------------------*/

}  // namespace Valkyrie::Thread

#endif  /* !VALKYRIE_THREAD_LISTING_HPP */
