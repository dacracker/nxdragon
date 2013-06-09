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
    /* OSAtomicIncrement32 returns the _previous_ value of the variable */
    return OSAtomicIncrement32(value)+1;
}

/*************************************************************/
int nx_atomic_dec(volatile nxint32* value)
{
    /* OSAtomicDecrement32 returns the _previous_ value of the variable */
    return OSAtomicDecrement32(value)-1;
}

/*************************************************************/
int nx_atomic_value(volatile nxint32* value)
{
    /* Not sure if this is the best way to do it but should work.. */
    return OSAtomicAdd32(0, value);
}
