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

#include "gui/nx_window.h"
#include "kernel/nx_event_queue.h"
#include "kernel/nx_event_source.h"
#include "kernel/nx_timer.h"

int main(int args, char **argv)
{
	nx_window *window;
	nx_event_queue *event_queue;
	nx_event *event; 
	nxbool time_to_quit = nxfalse;

	NX_UNUSED(args);
	NX_UNUSED(argv);

	window = nx_window_create("Simple window",800,600);
	event_queue = nx_event_queue_create();

	/* Connect the event queue to the window */
	nx_event_source_register(nx_window_event_source(window),event_queue);

	while(!time_to_quit)
	{
		/* Wait at most 20ms for a new event to occur */
		if((event = nx_event_queue_wait_next(event_queue,20)) != 0)
		{
			if(event->type == NX_EVENT_WINDOW_CLOSED)
				time_to_quit = nxtrue;

			/* Any event we recieve must be released, otherwise we'll have a memory leak on our hands */
			nx_event_release(event);
		}
	}

	nx_window_delete(window);

	nx_event_queue_delete(event_queue);

	return 0;
}
