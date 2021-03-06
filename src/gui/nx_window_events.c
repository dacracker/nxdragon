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

#include "nx_window_events.h"
#include "../kernel/nx_memory.h"

/*************************************************************/
window_closed_event* _nx_create_window_closed_event(struct nx_window_t *window)
{
	window_closed_event *event = nx_malloc(sizeof(window_closed_event));
	nx_event_init(&event->base,(nx_event_type)NX_EVENT_WINDOW_CLOSED,0);
	event->window = window;

	return event;
}
