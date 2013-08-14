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

/*************************************************************/
void test_ticks(void *status)
{
	nxuint32 _start_point;

	/* Initialize ticks module */ 
	nx_ticks_init();

	/* Sleep for a few milliseconds*/ 
	nx_sleep(25);

	/* Get the starting point */ 
	_start_point = nx_get_ticks();

	nx_assert(_start_point > 0);

	/* Sleep for 25ms, this really should definitely give us a new tick count since _start_point */
	nx_sleep(25);

	nx_assert(_start_point != nx_get_ticks());
}
