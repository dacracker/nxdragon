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

#include "nx_thread.h"
#include "nx_memory.h"
#include "nx_platform.h"

#include <pthread.h>
#include <sys/types.h>

struct nx_thread_t {
	pthread_t handle; 
	nx_thread_proc proc; 
	void *param;
	nxbool time_to_quit,
		   is_running; 
};

/*************************************************************/
void* _nx_thread_exec(struct nx_thread_t *thread)
{
	thread->is_running = nxtrue; 

	(*thread->proc)(thread,thread->param);

	thread->is_running = nxfalse;

	return 0;
}

/*************************************************************/
struct nx_thread_t* nx_thread_begin(nx_thread_proc proc, void *param)
{
	struct nx_thread_t *thread;
	pthread_attr_t attribute;

	if(!proc)
		return 0;

	thread = nx_malloc(sizeof(nx_thread));

	thread->proc = proc;
	thread->param = param; 
	thread->time_to_quit = nxfalse;
	thread->is_running = nxfalse;

	pthread_attr_init(&attribute);
	if(pthread_attr_setdetachstate(&attribute, PTHREAD_CREATE_JOINABLE) == 0)
	{
		if(pthread_create(&thread->handle,
					      &attribute,
					      (void *(*) (void *))&_nx_thread_exec,
					      thread) == 0)
			return thread;
	}

	nx_free(thread);
	return 0;
}

/*************************************************************/
void nx_thread_end(nx_thread *self)
{
	if(nx_thread_is_running(self))
		nx_thread_quit(self);

	nx_thread_wait(self,0);

	nx_free(self); 
}

/*************************************************************/
nxbool nx_thread_is_running(nx_thread *self)
{
	return self->is_running; 
}

/*************************************************************/
nxuint32 nx_thread_id(struct nx_thread_t *self)
{
	return (nxuint32)self->handle;
}

/*************************************************************/
nxbool nx_thread_time_to_quit(nx_thread *self)
{
	return self->time_to_quit; 
}

/*************************************************************/
void nx_thread_quit(nx_thread *self)
{
	self->time_to_quit = nxtrue;
}

/*************************************************************/
nxbool nx_thread_wait(nx_thread *self, nxuint32 timeout_ms)
{
	struct timespec timeout_spec;

	if(nx_thread_is_running(self) != nxtrue)
		return nxtrue;

	/* wait forever */
	if(timeout_ms == 0)
	{
		if(!pthread_join(self->handle, 0))
			return nxtrue;
		
		return nxfalse;
	}

#ifndef NX_OS_MACX
	timeout_spec.tv_sec = timeout_ms / 1000;
	timeout_spec.tv_nsec = (timeout_ms % 1000) * 1000;

	if(!pthread_timedjoin_np(self->handle, 0, &timeout_spec))
		return nxtrue;
#endif
	
	return nxfalse;
}

/*************************************************************/
nxuint32 nx_current_thread_id()
{
	return pthread_self();
}
