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

/** Initializes tick count system */
NX_KERNEL_API void nx_ticks_init(void);

/** Returns the number of ticks since application startup */ 
NX_KERNEL_API nxuint32 nx_get_ticks(void);

/** Puts the current thread to sleep for at least <ms> milliseconds*/ 
NX_KERNEL_API void nx_sleep(nxuint32 ms);

/** @} @} */

#endif 
