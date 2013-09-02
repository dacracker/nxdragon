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

#include "nx_mutex.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "nx_memory.h"

struct nx_mutex_t {
	CRITICAL_SECTION critSection;
};

/*************************************************************/
nx_mutex* nx_mutex_create()
{
	struct nx_mutex_t *self = nx_malloc(sizeof(struct nx_mutex_t));
	InitializeCriticalSectionEx(&self->critSection,
								1200, /* HACK: Run this spin count through some profiling tests */
								CRITICAL_SECTION_NO_DEBUG_INFO);
	return self;
}

/*************************************************************/
void nx_mutex_destroy(nx_mutex *self)
{
	DeleteCriticalSection(&self->critSection);
	nx_free(self);
}

/*************************************************************/
void nx_mutex_lock(nx_mutex *self)
{
	EnterCriticalSection(&self->critSection);
}

/*************************************************************/
void nx_mutex_unlock(nx_mutex *self)
{
	LeaveCriticalSection(&self->critSection);
}
