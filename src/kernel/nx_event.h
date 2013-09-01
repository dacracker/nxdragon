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

#ifndef __NX_KERNEL_EVENT_H__
#define __NX_KERNEL_EVENT_H__

#include "nx_bool.h"
#include "nx_def.h"


/** \ingroup NxKernel
  * \defgroup nx_event nx_event
  * \brief Base event object
  * TODO
  * @{
  */

typedef enum nx_event_type_t {
	NX_EVENT_KERNEL_EVENTS = 0, /* Meta event */
	NX_EVENT_QUIT, /* Symbolizes a quit notification */
	NX_EVENT_GUI_EVENTS = 1000,
	NX_EVENT_USER_EVENTS = 32000 /* All user events must be have a number larger than NX_EVENT_USER_EVENT */
} nx_event_type;

typedef struct nx_event_source_t nx_event_source; 

#define nx_is_kernel_event(event_type) (event_type < NX_EVENT_GUI_EVENTS) ? nxtrue : nxfalse
#define nx_is_gui_event(event_type) (event_type > NX_EVENT_GUI_EVENTS && event_type < NX_EVENT_USER_EVENTS) ? nxtrue : nxfalse
#define nx_is_user_event(event_type) (event_type > NX_EVENT_USER_EVENTS) ? nxtrue : nxfalse

typedef struct nx_event_t {
	nx_event_type type; /* Describes the type of the event */ 
	int ref; /* Reference count */
	nx_event_source *event_source; /* Pointer to the event source that generated the event */
	void (*destructor)(struct nx_event_t*); /* The destructor is responsible for freeing all the data occupied by the event */ 
} nx_event;

typedef void (*nx_event_dtor)(struct nx_event_t*);

/** Initializes the event. the destructor may be set to 0 if no custom allocations are made by the event */
NX_KERNEL_API void nx_event_init(nx_event *self, nx_event_type type, void (*destructor)(struct nx_event_t*));

/** Increases the reference count of the event by 1*/
NX_KERNEL_API void nx_event_ref(nx_event *self);

/** Decreasess reference count of the event by 1. The event will be destroyed when the reference count turns 0*/
NX_KERNEL_API void nx_event_release(nx_event *self);

/** @} @} */

#endif
