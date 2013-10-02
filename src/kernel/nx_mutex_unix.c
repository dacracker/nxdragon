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
#include "nx_memory.h"

#include <pthread.h>

struct nx_mutex_t {
	pthread_mutex_t mtx; 
};

/*************************************************************/
nx_mutex* nx_mutex_create()
{
	struct nx_mutex_t *self;
	pthread_mutexattr_t attr;

	self = nx_malloc(sizeof(struct nx_mutex_t));
    
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    
    pthread_mutex_init(&self->mtx, &attr);
    
    pthread_mutexattr_destroy(&attr);

	return self; 
}

/*************************************************************/
void nx_mutex_delete(nx_mutex *self)
{
	pthread_mutex_destroy(&self->mtx);
	free(self);
}

/*************************************************************/
void nx_mutex_lock(nx_mutex *self)
{
	pthread_mutex_lock(&self->mtx);
}

/*************************************************************/
void nx_mutex_unlock(nx_mutex *self)
{
	pthread_mutex_unlock(&self->mtx);
}
