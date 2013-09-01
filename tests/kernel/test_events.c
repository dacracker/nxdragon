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

#include "test_events.h"
#include "kernel/nx_event_source.h"
#include "kernel/nx_event_queue.h"

#include "utest/nx_utest.h"

#include <stdlib.h>

typedef enum test_events_t {
	NX_EVENT_DUMMY1 = NX_EVENT_USER_EVENTS + 1
} test_events;

typedef struct _nx_event_dummy1_t {
	nx_event base;
	int count; 
} _nx_event_dummy1;

int dummy1_count = 0;

/*************************************************************/
static void dummy1_dtor(_nx_event_dummy1 *event)
{
	--dummy1_count;
	free(event);
}

/*************************************************************/
static _nx_event_dummy1* _create_dummy1_event()
{
	_nx_event_dummy1 *dummy = malloc(sizeof(_nx_event_dummy1));
	nx_event_init(&dummy->base,NX_EVENT_DUMMY1,(nx_event_dtor)dummy1_dtor);
	++dummy1_count;
	return dummy;
}

/*************************************************************/
void test_event_source_empty(void *status)
{
	nx_event_source *event_source;
	_nx_event_dummy1 *event = _create_dummy1_event();

	event_source = nx_event_source_create(); 

	/* Emit the event to the void */
	nx_event_source_emit(event_source,(nx_event*)event); 

	nx_event_source_delete(event_source);

	nx_assert(dummy1_count == 0);
}

/*************************************************************/
void test_event_source_queue_reg(void *status)
{
	nx_event_source *event_source;
	nx_event_queue *event_queue1,
				   *event_queue2;

	event_source = nx_event_source_create();

	event_queue1 = nx_event_queue_create();
	event_queue2 = nx_event_queue_create();

	/* It's illegal to register a NULL pointer */
	nx_assert_equal(nx_event_source_register(event_source,0),nxfalse);

	/* First registration is unique, should be allowed */
	nx_assert_equal(nx_event_source_register(event_source,event_queue1),nxtrue);

	/* Multiple registrations should be stoppped */
	nx_assert_equal(nx_event_source_register(event_source,event_queue1),nxfalse);

	/* Adding another new object should be allowed */
	nx_assert_equal(nx_event_source_register(event_source,event_queue2),nxtrue);

	/* We should be allowed to remove a registered event queue */
	nx_assert_equal(nx_event_source_unregister(event_source,event_queue1),nxtrue);

	/* But we can't unregister it twice */
	nx_assert_equal(nx_event_source_unregister(event_source,event_queue1),nxfalse);

	/* Invalid queues cannot be added and therefore cannot be removed */
	nx_assert_equal(nx_event_source_unregister(event_source,0),nxfalse);

	/* We should be allowed to register our queue now that it has been removed */
	nx_assert_equal(nx_event_source_register(event_source,event_queue1),nxtrue);

	nx_event_queue_delete(event_queue1);
	nx_event_queue_delete(event_queue2);

	nx_event_source_delete(event_source);
}

/*************************************************************/
void test_event_source_single_queue(void *status)
{
	nx_event_source *event_source;
	nx_event_queue *event_queue;
	nx_event *event;
	int index = 0,
		event_count = 0;

	event_source = nx_event_source_create();
	event_queue = nx_event_queue_create();
	
	/* Attempt to register the event queue */
	nx_assert_equal(nx_event_source_register(event_source,event_queue),nxtrue);

	while(index < 10)
	{
		if(index++ >= 5)
		{
			event = (nx_event*)_create_dummy1_event();

			/* Emit the event */
			nx_event_source_emit(event_source,(nx_event*)event);
		}

		if((event = nx_event_queue_peek_next(event_queue)) != 0)
		{
			++event_count;
			nx_event_release(event);
		}
	}

	nx_event_queue_delete(event_queue);
	nx_event_source_delete(event_source);

	nx_assert_equal(event_count,5);
}

/*************************************************************/
void test_event_source_multiple_with_single_queue(void *status)
{
	nx_event *event;

	nx_event_source *event_source1,
					*event_source2;
	nx_event_queue *event_queue;

	dummy1_count = 0;

	event_queue = nx_event_queue_create();

	event_source1 = nx_event_source_create();
	event_source2 = nx_event_source_create();

	nx_event_source_register(event_source1,event_queue);
	nx_event_source_register(event_source2,event_queue);

	nx_event_source_emit(event_source1,(nx_event*)_create_dummy1_event());
	nx_event_source_emit(event_source2,(nx_event*)_create_dummy1_event());

	event = nx_event_queue_peek_next(event_queue);
	
	nx_assert(event != 0);
	nx_assert_equal(event->event_source,event_source1);

	nx_event_release(event);

	event = nx_event_queue_peek_next(event_queue);
	
	nx_assert(event != 0);
	nx_assert_equal(event->event_source,event_source2);

	nx_event_release(event);

	nx_event_queue_delete(event_queue);

	nx_event_source_delete(event_source1);
	nx_event_source_delete(event_source2);
}
