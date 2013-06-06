/*
  NxDragon Game Engine

  Author: Patrik Jeppsson <dacrackerx64@gmail.com>

  License: This source code is proprietary and may not
       be used without permission from the author. 
*/

#ifndef __NXDRAGON_KERNEL_ATOMIC_H__
#define __NXDRAGON_KERNEL_ATOMIC_H__

#include "nx_def.h"
#include "nx_types.h"

/** \defgroup nx_atomic nx_atomic
  * A collection of functions guaranteed to perform
  * their operations atomically on all supported platforms. 
  * @{
  */

/** Increments the value by 1 */
NX_KERNEL_API int nx_atomic_inc(volatile nxint32* value);

/** Decrements the value by 1 */
NX_KERNEL_API int nx_atomic_dec(volatile nxint32* value);

/** Returns the current value of value */
NX_KERNEL_API int nx_atomic_read(volatile nxint32* value);

/** @} */
#endif
