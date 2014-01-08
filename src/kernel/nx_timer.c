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

#include "nx_timer.h"

#include "nx_memory.h"
#include "nx_thread.h"
#include "nx_mutex.h"
#include "nx_list.h"

struct _nx_timer {
	nx_timer_proc proc;
	void *param; 
	nxuint32 id,
			 last_run,
			 interval; 
};

static nx_thread *_nx_timer_thread = 0; 
static nx_mutex *_nx_timers_mutex = 0; 
static nx_list _nx_timer_list;  

/*************************************************************/
void nx_timer_thread_proc(nx_thread *self, void *param)
{
	nxuint32 current_tick; 
	int index; 
	struct _nx_timer *timer; 

	NX_UNUSED(param); 

	current_tick = nx_get_ticks(); 

	while(!nx_thread_time_to_quit(self))
	{
		nx_mutex_lock(_nx_timers_mutex); 
		for(index = 0; index < nx_list_size(&_nx_timer_list); ++index)
		{
			timer = nx_list_at(&_nx_timer_list,index); 

			if((current_tick - timer->last_run) >= timer->interval)
			{
				timer->interval = (*timer->proc)(timer->interval,timer->param);

				if(timer->interval == 0)
				{
					nx_free(timer); 
					nx_list_remove_at(&_nx_timer_list,index);
				}
				else 
				{
					timer->last_run = current_tick;
				}
			}
		}
		nx_mutex_unlock(_nx_timers_mutex); 

		/* Prevent the thread from hogging the CPU */
		nx_sleep(10); 

		current_tick = nx_get_ticks(); 
	}

	nx_mutex_lock(_nx_timers_mutex); 
	for(index = 0; index < nx_list_size(&_nx_timer_list); ++index)
	{
		timer = nx_list_at(&_nx_timer_list,index); 
		nx_free(timer); 
	}
	nx_mutex_unlock(_nx_timers_mutex); 
}

/*************************************************************/
nxuint32 nx_timer_start(nxuint32 interval,
						nx_timer_proc proc,
						void *param)
{
	struct _nx_timer *timer;

	if(!interval || !proc || nx_thread_time_to_quit(_nx_timer_thread))
		return 0; 

	timer = nx_malloc(sizeof(struct _nx_timer));

	if(!timer)
		return 0; 

	timer->interval = interval; 
	timer->proc = proc; 
	timer->param = param; 

	nx_mutex_lock(_nx_timers_mutex); 
	/* Generate a unique id for our new timer */
	timer->id = nx_list_size(&_nx_timer_list) + 1;

	nx_list_append(&_nx_timer_list,timer); 

	nx_mutex_unlock(_nx_timers_mutex); 

	return timer->id;
}

/*************************************************************/
nxbool nx_timer_stop(nxuint32 timer_id)
{
	struct _nx_timer *timer;
	int index; 

	nx_mutex_lock(_nx_timers_mutex); 
	for(index = 0; index < nx_list_size(&_nx_timer_list); ++index)
	{
		timer = nx_list_at(&_nx_timer_list,index);

		if(timer->id == timer_id)
		{
			nx_list_remove_at(&_nx_timer_list,index);
			nx_free(timer);
			
			nx_mutex_unlock(_nx_timers_mutex); 
			return nxtrue;
		}
	}
	nx_mutex_unlock(_nx_timers_mutex); 

	return nxfalse; 
}

/*************************************************************/
nxbool _nx_start_timer_thread(void)
{
	if(_nx_timer_thread != 0)
		return nxfalse; 

	nx_list_init(&_nx_timer_list); 
	_nx_timers_mutex = nx_mutex_create(); 

	_nx_timer_thread = nx_thread_begin(&nx_timer_thread_proc,0); 

	return _nx_timer_thread ? nxtrue : nxfalse; 	
}

/*************************************************************/
nxbool _nx_stop_timer_thread(void)
{
	if(!_nx_timer_thread)
		return nxfalse; 

	nx_thread_end(_nx_timer_thread); 

	nx_mutex_delete(_nx_timers_mutex); 

	nx_list_delete(&_nx_timer_list);

	return nxtrue; 
}
