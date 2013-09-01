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

#ifndef __NX_KERNEL_EVENT_SOURCE_H__
#define __NX_KERNEL_EVENT_SOURCE_H__

#include "nx_event.h"

/** \ingroup NxKernel
  * \defgroup nx_event_source nx_event_source
  * \brief Event source  
  * TODO
  * @{
  */
struct nx_event_queue_t;

/** Creates a new event source */
NX_KERNEL_API nx_event_source* nx_event_source_create(void);

/** Deletes the event source */
NX_KERNEL_API void nx_event_source_delete(nx_event_source *self);

/** Registers a new event queue that will recieve events from this event source */
NX_KERNEL_API nxbool nx_event_source_register(nx_event_source *self, struct nx_event_queue_t *event_queue);

/** Unregisters a current event queue, it will no longer recieve events from this event source */
NX_KERNEL_API nxbool nx_event_source_unregister(nx_event_source *self, struct nx_event_queue_t *event_queue);

/** Emits the event to all registered event queues. The event MUST be allocated on the heap */
NX_KERNEL_API void nx_event_source_emit(nx_event_source *self, nx_event *event);

/** @} @} */

#endif
