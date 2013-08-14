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

#include "nx_types.h"

#include <sys/time.h>
#include <unistd.h>
#include <errno.h>

#define __USE_POSIX199309
#include <time.h>

/* One of these objects will keep track of the starting point of the application */ 
static struct timespec _start_ts;
static struct timeval _start_tv; 

/*************************************************************/
static nxuint32 _nx_time_get_ticks_monotonic(void)
{
	struct timespec now_ts;
	clock_gettime(CLOCK_MONOTONIC, &now_ts);

	return (now_ts.tv_sec - _start_ts.tv_sec) * 1000 + 
		   (now_ts.tv_nsec - _start_ts.tv_nsec)/1000000;   
}

/*************************************************************/
static nxuint32 _nx_time_get_ticks_tod(void)
{
	struct timeval now_tv;
	gettimeofday(&now_tv,0);

	return (now_tv.tv_sec - _start_tv.tv_sec) * 1000 +
		   (now_tv.tv_usec - _start_tv.tv_usec)/1000; 
}

/* Pointer to the internal get tick function */
static nxuint32 (*_nx_get_ticks)(void) = _nx_time_get_ticks_tod;  

/*************************************************************/
void nx_ticks_init(void) 
{
	/* The monotonic clock is preferable since it's faster
	   and more accurate. */
	if(clock_gettime(CLOCK_MONOTONIC, &_start_ts) == 0) {
		_nx_get_ticks = &_nx_time_get_ticks_monotonic;
		return;
	}

	gettimeofday(&_start_tv,0);
}

/*************************************************************/
nxuint32 nx_get_ticks(void) 
{
	return (*_nx_get_ticks)();
} 

/*************************************************************/
void nx_sleep(nxuint32 ms)
{
	struct timespec time_left_ts, 
					naptime_ts;

	int status;

	/* Calculate the timeout interval */
	time_left_ts.tv_sec = ms/1000;
	time_left_ts.tv_nsec = (ms % 1000) * 1000000;

	do
	{
		/* time_left_ts contains how muc longer we need to sleep*/ 
		naptime_ts.tv_sec = time_left_ts.tv_sec;
		naptime_ts.tv_nsec = time_left_ts.tv_nsec;

		/* Reset the error status for now */
		errno = 0;

		/* Try to sleep for the specified amount of time.
		   time_left_ts will be updated with how much
		   longer we need to sleep to fulfill the caller's
		   wish. */ 
		status = nanosleep(&naptime_ts,&time_left_ts);
	}
	while(status && (errno == EINTR));
}
