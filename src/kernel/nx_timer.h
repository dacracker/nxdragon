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

#ifndef __NX_KERNEL_TIMER_H__
#define __NX_KERNEL_TIMER_H__

#include "nx_def.h"
#include "nx_types.h"

/** \ingroup NxKernel
  * \defgroup nx_timer nx_timer
  * \brief timer functions
  * 
  * Please not that the function nx_time_init _must_
  * be called before any other timer related functions
  * can be used. The return value of the other timer 
  * functions will be unpredictable otherwise. 
  * @{
  */

typedef nxuint32 (*nx_timer_proc)(nxuint32,void*); 

/** Creates a new timer which will fire the chosen
  *	function at the given interval. The param will
  *	be sent to the function when it's fired. The function
  *	should return the new interval as it's return value.
  *	the timer is stoped if a value of 0 is returned.
  */
NX_KERNEL_API nxuint32 nx_timer_start(nxuint32 interval,
									  nx_timer_proc proc,
									  void *param); 

/** Returns the number of ticks since application startup */ 
NX_KERNEL_API nxuint32 nx_get_ticks(void);

/** Puts the current thread to sleep for at least <ms> milliseconds*/ 
NX_KERNEL_API void nx_sleep(nxuint32 ms);




/* WARNING: the following functions are private and most _only_ 
			be called from _within_ the kernel module. */

/** Initializes timer subsystem */
void _nx_timer_init(void);

nxbool _nx_start_timer_thread(void); 
nxbool _nx_stop_timer_thread(void);  

/** @} @} */

#endif 
