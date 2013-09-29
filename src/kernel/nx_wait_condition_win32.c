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

#include "nx_wait_condition.h"
#include "nx_memory.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

struct nx_wait_condition_t {
	CONDITION_VARIABLE cond; 
};

/*************************************************************/
nx_wait_condition* nx_wait_condition_create()
{
	nx_wait_condition *wait_condition = nx_malloc(sizeof(nx_wait_condition));
	InitializeConditionVariable(&wait_condition->cond);
	return wait_condition;
}

/*************************************************************/
void nx_wait_condition_delete(nx_wait_condition *self)
{
	nx_free(self); 
}

/*************************************************************/
void nx_wait_condition_wake_one(nx_wait_condition *self)
{
	WakeConditionVariable(&self->cond);
}

/*************************************************************/
void nx_wait_condition_wake_all(nx_wait_condition *self)
{
	WakeAllConditionVariable(&self->cond);
}

/*************************************************************/
int nx_wait_condition_wait(nx_wait_condition *self, nx_mutex *mutex, int timeout)
{
	const BOOL result = SleepConditionVariableCS(&self->cond,
												(CRITICAL_SECTION*)mutex,
												 timeout < 1 ? INFINITE : timeout); 

	if(result != FALSE)
		return 1; /* 1 means success */

	/* -1 means timeout and 0 means "other error" */
	return GetLastError() == ERROR_TIMEOUT ? -1 : 0;
}
