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

#ifndef __NX_KERNEL_THREAD_H__
#define __NX_KERNEL_THREAD_H__

#include "nx_def.h"
#include "nx_types.h"

/** \ingroup NxKernel
  * \defgroup nx_thread nx_thread
  * \brief Thread object 
  * TODO
  * @{
  */

typedef struct nx_thread_t nx_thread;
typedef void (*nx_thread_proc)(nx_thread *self, void*); 

/** Starts a new thread */
NX_KERNEL_API nx_thread* nx_thread_begin(nx_thread_proc proc, void *param); 

/** Deletes the thread object. This function will wait for the thread
  * to quit if it's still running. 
  */
NX_KERNEL_API void nx_thread_end(nx_thread *self);

/** Returns nxtrue if the thread is running, nxfalse if not */
NX_KERNEL_API nxbool nx_thread_is_running(nx_thread *self); 

/** Returns the thread's ID */
NX_KERNEL_API nxuint32 nx_thread_id(nx_thread *self); 

/** Returns nxtrue if someone requested that the thread should quit */
NX_KERNEL_API nxbool nx_thread_time_to_quit(nx_thread *self); 

/** Tells the thread that it should stop */
NX_KERNEL_API void nx_thread_quit(nx_thread *self); 

/** Waits for the thread to quit. If timeoutMs is set to 0 means
  * that the caller should wait no matter how long it takes.
  * The timeout it specified in milliseconds. 
  */ 
NX_KERNEL_API nxbool nx_thread_wait(nx_thread *self, nxuint32 timeoutMs); 

/** Returns the thread id of the currently running thread */
NX_KERNEL_API nxuint32 nx_current_thread_id(void); 

/** @} @} */
#endif
