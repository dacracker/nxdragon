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

#ifndef __NX_KERNEL_EVENT_QUEUE_H__
#define __NX_KERNEL_EVENT_QUEUE_H__

#include "nx_event.h"

typedef struct nx_event_queue_t nx_event_queue;

/** Creates a new event queue */
NX_KERNEL_API nx_event_queue* nx_event_queue_create(void); 

/** Deletes the event queue */
NX_KERNEL_API void nx_event_queue_delete(nx_event_queue *self); 

/** Inserts a new event in the event queue */
NX_KERNEL_API void nx_event_queue_insert(nx_event_queue *self, nx_event *event); 

/** Checks if there are any pending events in the queue and returns the next event, if any. The caller is responsible for invoking nx_event_release() on the event */ 
NX_KERNEL_API nx_event* nx_event_queue_peek_next(nx_event_queue *self);

#endif
