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

#include "nx_init.h"

#include "nx_timer.h"

/*************************************************************/
nxbool nx_kernel_init(void)
{
	/* Initialize the timer subsystem */
	_nx_timer_init(); 

	/* Start the timer thread */
	_nx_start_timer_thread();

	return nxtrue; 
}

/*************************************************************/
void nx_kernel_shutdown(void)
{
	/* Stop the timer thread */
	_nx_stop_timer_thread();
}
