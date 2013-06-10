/*
	NxDragon Game Engine

	Author: Patrik Jeppsson <dacrackerx64@gmail.com>

	License: This source code is proprietary and may not
			 be used without permission from the author. 
*/

#include "nx_atomic.h"

#include <libkern/OSAtomic.h>

/*************************************************************/
int nx_atomic_inc(volatile nxint32* value)
{
    return OSAtomicIncrement32(value);
}

/*************************************************************/
int nx_atomic_dec(volatile nxint32* value)
{
    return OSAtomicDecrement32(value);
}

/*************************************************************/
int nx_atomic_value(volatile nxint32* value)
{
    return OSAtomicAdd32(0, value);
}
