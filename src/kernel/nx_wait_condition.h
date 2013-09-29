/***************************************************************************\
  This file is part of the NxDragon Game Engine.

  Copyright 2013 Patrik Jeppsson

  NxDragon is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  NxDragon is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with NxDragon. If not, see <http://www.gnu.org/licenses/>.
\***************************************************************************/

#ifndef __NX_KERNEL_WAITCONDITION_H__
#define __NX_KERNEL_WAITCONDITION_H__

#include "nx_def.h"
#include "nx_mutex.h"
#include "nx_bool.h"

/** \ingroup NxKernel
  * \defgroup nx_wait_condition nx_wait_condition
  * \brief wait condition 
  *
  * A wait condition is a synconization tool for threads.
  * @{
  */

typedef struct nx_wait_condition_t nx_wait_condition; 

/** Creates a new wait condition */
NX_KERNEL_API nx_wait_condition* nx_wait_condition_create();

/** Deletes a wait condition */
NX_KERNEL_API void nx_wait_condition_delete(nx_wait_condition *self);

/** Wakes one, randomly selected, thread that is waiting for this wait condition */
NX_KERNEL_API void nx_wait_condition_wake_one(nx_wait_condition *self);

/** Wakes all threads waiting on this wait condition */
NX_KERNEL_API void nx_wait_condition_wake_all(nx_wait_condition *self);

/** Waits for the wait condition to be signaled via nx_wait_condition_wake_one() or nx_wait_condition_wake_all().
  * If a timeout of <= 0 is given that means that there's no timeout and the function will only return if it's
  * signaled, if ever. The timeout is measured in milliseconds. 
  * This function returns 1 if it succeeds, -1 if it timed out and 0 if it fails.  
  * the time-out interval elapsed. 
  */
NX_KERNEL_API int nx_wait_condition_wait(nx_wait_condition *self, nx_mutex *mutex, int timeout); 

/** @} @} */

#endif
