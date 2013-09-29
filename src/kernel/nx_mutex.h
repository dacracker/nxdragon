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

#ifndef __NX_KERNEL_MUTEX_H__
#define __NX_KERNEL_MUTEX_H__

#include "nx_def.h"

/** \ingroup NxKernel
  * \defgroup nx_mutex nx_mutex
  * \brief Mutex syncronization object 
  * Lightweight synconization primitive. It's primary purpose
  * is to protect a piece of code that must not be run by
  * multiple threads at once. 
  * It's possible to aquire the mutex lock recursively. 
  * @{
  */

typedef struct nx_mutex_t nx_mutex; 

/** Creates a new mutex object */
NX_KERNEL_API nx_mutex* nx_mutex_create();

/** Destroys the mutex */
NX_KERNEL_API void nx_mutex_delete(nx_mutex *self);

/** Locks the mutex. Every call to this function must be paired with 
  * corresponding call to nx_mutex_unlock() with the same mutex as argument 
  */
NX_KERNEL_API void nx_mutex_lock(nx_mutex *self);

/** Unlocks the mutex. The mutex _must_ be locked before an attempt to unlock it is made. */
NX_KERNEL_API void nx_mutex_unlock(nx_mutex *self);

/** @} @} */

#endif
