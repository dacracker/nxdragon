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

#ifndef __NX_KERNEL_QUEUE_H__
#define __NX_KERNEL_QUEUE_H__

#include "nx_types.h"
#include "nx_def.h"

/** \ingroup NxKernel
  * \defgroup nx_queue nx_queue
  * \brief generic FIFO container 
  *
  * A generic queue. It's optimized for
  * insertions at the back and removals
  * at the front. 
  * @{
  */

typedef struct nx_queue_t {
  NX_INTERNAL void** array; 
  nxuint32 front_index,
           size,
           capacity;
} nx_queue;

/** Initializes the queue object */
NX_KERNEL_API void nx_queue_init(nx_queue *self);

/** Frees the internal data structure allocated by the queue*/
NX_KERNEL_API void nx_queue_delete(nx_queue *self);

/** Enqueues a new value in the queue */
NX_KERNEL_API void nx_queue_enqueue(nx_queue *self, void *data);

/** Removes the front object in the queue and returns it, returns 0 if the queue is empty */
NX_KERNEL_API void* nx_queue_dequeue(nx_queue *self);

/** Returns the index located at the giveń index. This function is unsafe if the given index is invalid */
NX_KERNEL_API void* nx_queue_at(const nx_queue *self, int index);

/** Safe, but slower version of nx_queue_at. 0 will be returned if the index is invalid. */
NX_KERNEL_API void* nx_queue_value(const nx_queue *self, int index);

/** Returns the current size of the queue */
NX_KERNEL_API int nx_queue_size(const nx_queue *self);

/** @} @} */
#endif 
