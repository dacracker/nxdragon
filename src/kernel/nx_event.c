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

#include "nx_event.h"
#include "nx_atomic.h"

#include "nx_memory.h"

/*************************************************************/
void nx_event_init(nx_event *self, nx_event_type type, void (*destructor)(struct nx_event_t*))
{
	self->type = type;
	self->destructor = destructor;

	self->ref = 0;
	self->event_source = 0; /* This param will be set when the event is emitted */
}

/*************************************************************/
void nx_event_ref(nx_event *self)
{
	nx_atomic_inc(&self->ref);
}

/*************************************************************/
void nx_event_release(nx_event *self)
{
	if(nx_atomic_dec(&self->ref) == 0)
	{
		if(self->destructor != 0) {
			(*self->destructor)(self);
		}
		else {
			nx_free(self);
		}
	}
}
