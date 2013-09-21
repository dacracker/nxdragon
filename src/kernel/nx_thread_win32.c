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

#include "nx_thread.h"
#include "nx_memory.h"

#include <windows.h>
#include <process.h>

struct nx_thread_t {
	uintptr_t handle; 
	nx_thread_proc proc; 
	void *param; 
	nxuint32 threadId;
	nxbool time_to_quit,
		   is_running; 
};

/*************************************************************/
int WINAPI _nx_thread_exec(struct nx_thread_t *thread)
{
	thread->is_running = nxtrue; 

	(*thread->proc)(thread,thread->param);

	thread->is_running = nxfalse; 

	/* We need to call this function to let Windows 
	   cleaup it's internal resources */
	_endthreadex(0);
	return 0;
}

/*************************************************************/
struct nx_thread_t* nx_thread_begin(nx_thread_proc proc, void *param)
{
	struct nx_thread_t *thread;

	if(!proc)
		return 0;

	thread = nx_malloc(sizeof(nx_thread));

	if(!thread)
		return 0;

	thread->proc = proc;
	thread->param = param; 
	thread->time_to_quit = nxfalse;
	thread->is_running = nxfalse; 

	thread->handle = _beginthreadex(0,0,
									(unsigned int (WINAPI*)(void*))&_nx_thread_exec,
									thread,
									0,
									&thread->threadId);

	return thread;
}

/*************************************************************/
void nx_thread_end(nx_thread *self)
{
	if(nx_thread_is_running(self))
	{
		nx_thread_quit(self);
		nx_thread_wait(self,0);
	}

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
	return self->threadId;
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
nxbool nx_thread_wait(nx_thread *self, nxuint32 timeoutMs)
{
	if(nx_thread_is_running(self) != nxtrue)
		return nxtrue; 

	return WaitForSingleObject((HANDLE)self->handle,timeoutMs) == WAIT_OBJECT_0 ? nxtrue : nxfalse; 
}

/*************************************************************/
nxuint32 nx_current_thread_id()
{
	return GetCurrentThreadId(); 
}
