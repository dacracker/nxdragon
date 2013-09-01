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

#include "nx_event_queue.h"
#include "nx_queue.h"

#include <stdlib.h>

typedef struct nx_event_queue_t {
	nx_queue events; /* This structure will probably need a mutex look in the near future */ 
} nx_event_queue;

/*************************************************************/
nx_event_queue* nx_event_queue_create(void)
{
	nx_event_queue *self = malloc(sizeof(nx_event_queue));
	nx_queue_init(&self->events);

	return self; 
}

/*************************************************************/
void nx_event_queue_delete(nx_event_queue *self)
{
	nx_queue_delete(&self->events);
	free(self);
}

/*************************************************************/
void nx_event_queue_insert(nx_event_queue *self, nx_event *event)
{
	/* Increase the event's reference count */ 
	nx_event_ref(event);

	/* Engueue the event in our internal queue */
	nx_queue_enqueue(&self->events,event); 
}

/*************************************************************/
nx_event* nx_event_queue_peek_next(nx_event_queue *self)
{
	/* The caller is responsible for calling nx_event_release() on the event */
	return nx_queue_dequeue(&self->events);
}
