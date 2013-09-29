/***************************************************************************\
  This file is part of the NxDragon Game Engine.

  Copyright 2013 Patrik Jeppsson, Ulf Johnsson

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

#include <pthread.h>

struct nx_wait_condition_t {
	pthread_cond_t cond; 
};

/*************************************************************/
nx_wait_condition* nx_wait_condition_create()
{
	nx_wait_condition *wait_condition = nx_malloc(sizeof(nx_wait_condition));
	if(pthread_cond_init(&wait_condition->cond, 0) == 0)
	   return wait_condition;

    nx_free(wait_condition);
    return 0;
}

/*************************************************************/
void nx_wait_condition_delete(nx_wait_condition *self)
{
    pthread_cond_destroy(&self->cond);
	nx_free(self);
}

/*************************************************************/
void nx_wait_condition_wake_one(nx_wait_condition *self)
{
	 pthread_cond_signal(&self->cond);
}

/*************************************************************/
void nx_wait_condition_wake_all(nx_wait_condition *self)
{
	 pthread_cond_broadcast(&self->cond);
}

/*************************************************************/
int nx_wait_condition_wait(nx_wait_condition *self, nx_mutex *mutex, int timeout)
{
    struct timespec timeout_spec;

    if(timeout < 1)
        return (pthread_cond_wait(&self->cond, (pthread_mutex_t*)mutex) == 0) ? 1 : 0;

    timeout_spec.tv_sec = timeout / 1000;
    timeout_spec.tv_nsec = (timeout % 1000) * 1000;

	return (pthread_cond_timedwait(&self->cond, (pthread_mutex_t*)mutex, &timeout_spec) == 0) ? 1 : 0;
}
