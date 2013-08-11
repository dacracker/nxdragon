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

#ifndef __NXDRAGON_KERNEL_ATOMIC_H__
#define __NXDRAGON_KERNEL_ATOMIC_H__

#include "nx_def.h"
#include "nx_types.h"

/** \ingroup NxKernel
  * \defgroup nx_atomic nx_atomic 
  * \brief atomic functions 
  *
  * A collection of functions guaranteed to perform
  * their operations atomically on all supported platforms. 
  * @{
  */

/** Increments the value by 1 */
NX_KERNEL_API int nx_atomic_inc(volatile nxint32* value);

/** Decrements the value by 1 */
NX_KERNEL_API int nx_atomic_dec(volatile nxint32* value);

/** Returns the current value of value */
NX_KERNEL_API int nx_atomic_value(volatile nxint32* value);

/** @} */
#endif
