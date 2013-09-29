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
#include "nx_mutex.h"
#include "nx_wait_condition.h"

#include "nx_memory.h"

struct nx_event_queue_t {
	nx_queue events; 
	nx_mutex *mutex;
	nx_wait_condition *wait_cond;
};

/*************************************************************/
nx_event_queue* nx_event_queue_create(void)
{
	struct nx_event_queue_t *self = nx_malloc(sizeof(struct nx_event_queue_t));
	nx_queue_init(&self->events);

	self->mutex = nx_mutex_create();
	self->wait_cond = nx_wait_condition_create(); /* We need this for timed waits */

	return self; 
}

/*************************************************************/
void nx_event_queue_delete(nx_event_queue *self)
{
	nx_wait_condition_delete(self->wait_cond);
	nx_mutex_delete(self->mutex);
	nx_queue_delete(&self->events);
	nx_free(self);
}

/*************************************************************/
void nx_event_queue_insert(nx_event_queue *self, nx_event *event)
{
	/* Increase the event's reference count */ 
	nx_event_ref(event);

	nx_mutex_lock(self->mutex);

	/* Engueue the event in our internal queue */
	nx_queue_enqueue(&self->events,event); 

	nx_mutex_unlock(self->mutex);

	/* A new event is available */
	nx_wait_condition_wake_one(self->wait_cond);
}

/*************************************************************/
nx_event* nx_event_queue_peek_next(nx_event_queue *self)
{
	nx_event *event;

	nx_mutex_lock(self->mutex);

	/* The caller is responsible for calling nx_event_release() on the event */
	event = nx_queue_dequeue(&self->events);

	nx_mutex_unlock(self->mutex);

	return event;
}

/*************************************************************/
nx_event* nx_event_queue_wait_next(nx_event_queue *self, int timeout)
{
	int wait_result;
	nxbool quit = nxfalse;
	nx_event *event;

	nx_mutex_lock(self->mutex);

	event = nx_queue_dequeue(&self->events);

	/* No need to wait if we already got an event */
	if(event != 0)
	{
		nx_mutex_unlock(self->mutex);
		return event; 
	}

	while(!quit)
	{
		/* Wait for a new event to become available */
		wait_result = nx_wait_condition_wait(self->wait_cond,self->mutex,timeout);

		/* We should return if the wait succeeded or if it timed out */
		if(wait_result != 0)
		{
			/* It's safe to call this function even if the queue is empty */
			event = nx_queue_dequeue(&self->events);

			/* Signal that the loop should quit */
			quit = nxtrue;
		}
	}

	nx_mutex_unlock(self->mutex);

	return event; 
}
