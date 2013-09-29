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

#ifndef __NX_GUI_WINDOW_EVENTS_H__
#define __NX_GUI_WINDOW_EVENTS_H__

#include "../kernel/nx_event.h"

enum NX_WINDOW_EVENTS 
{
	NX_EVENT_WINDOW_CLOSED = NX_EVENT_GUI_EVENTS + 1
};

typedef struct window_closed_event_t {
	nx_event base;
	struct nx_window_t *window; /* The window which has been closed */
} window_closed_event;

NX_INTERNAL window_closed_event* _nx_create_window_closed_event(struct nx_window_t *window); 

#endif
