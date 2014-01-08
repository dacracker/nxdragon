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

#include "test_timer.h"

#include "kernel/nx_timer.h"
#include "utest/nx_utest.h"

/* This function represents our timer */
nxuint32 int_counter_timer(nxuint32 interval, void *param)
{
	/* Increase the counter variable */
	int *counter = param; 
	return --(*counter) <= 0 ? 0 : interval;
}

/*************************************************************/
void test_ticks(void *status)
{
	nxuint32 _start_point;

	/* Sleep for a few milliseconds*/ 
	nx_sleep(25);

	/* Get the starting point */ 
	_start_point = nx_get_ticks();

	nx_assert(_start_point > 0);

	/* Sleep for 25ms, this really should definitely give us a new tick count since _start_point */
	nx_sleep(25);

	nx_assert(_start_point != nx_get_ticks());
}

/*************************************************************/
void test_timer_start_stop(void *status)
{
	int counter1 = 10,
		counter2 = 5; 
	nxuint32 id1,id2; 

	id1 = nx_timer_start(25,int_counter_timer,&counter1);
	id2 = nx_timer_start(60,int_counter_timer,&counter2); 

	nx_assert_greater(id1,0);
	nx_assert_greater(id2,0);

	nx_assert(id1 != id2); 
	
	while((counter1 != 0) && (counter2 != 0))
		nx_sleep(100); 
}
