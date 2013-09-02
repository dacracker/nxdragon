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

#include "nx_event_source.h"
#include "nx_event_queue.h"
#include "nx_list.h"

#include "nx_memory.h"

struct nx_event_source_t {
  nx_list listeners; 
};

/*************************************************************/
nx_event_source* nx_event_source_create(void)
{	
	struct nx_event_source_t *self = nx_malloc(sizeof(struct nx_event_source_t));
	nx_list_init(&self->listeners);

	return self;
}

/*************************************************************/
void nx_event_source_delete(nx_event_source *self)
{
	nx_list_delete(&self->listeners);
	nx_free(self);
}

/*************************************************************/
nxbool nx_event_source_register(nx_event_source *self, nx_event_queue *event_queue)
{
	/* The event queue must be unique and valid object */
	if(event_queue == 0 || (nx_list_contains(&self->listeners,event_queue) == nxtrue))
		return nxfalse;

	nx_list_append(&self->listeners,event_queue);

	return nxtrue; 
}

/*************************************************************/
nxbool nx_event_source_unregister(nx_event_source *self, nx_event_queue *event_queue)
{
	int index = 0;

	if(event_queue == 0 || (nx_list_contains(&self->listeners,event_queue) == nxfalse))
		return nxfalse;

	while(index < nx_list_size(&self->listeners))
	{
		if(nx_list_at(&self->listeners,index) == event_queue)
		{
			nx_list_remove_at(&self->listeners,index);
			return nxtrue;
		}

		++index;
	}

	return nxfalse;
}

/*************************************************************/
void nx_event_source_emit(nx_event_source *self, nx_event *event)
{
	int index = 0;

	nx_event_ref(event); 

	/* Register the event source as the emitter of the event */
	event->event_source = self;

	while(index < nx_list_size(&self->listeners))
	{
		nx_event_queue_insert(nx_list_at(&self->listeners,index),event);
		++index;
	}

	nx_event_release(event); 
}
