/*
	NxDragon Game Engine

	Author: Patrik Jeppsson <dacrackerx64@gmail.com>

	License: This source code is proprietary and may not
			 be used without permission from the author. 
*/

#include "nx_atomic.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <intrin.h>

LONG __cdecl _InterlockedIncrement(volatile LONG*);
LONG __cdecl _InterlockedDecrement(volatile LONG*);
LONG __cdecl _InterlockedCompareExchange(volatile LONG*,LONG,LONG); 

#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedCompareExchange)

/*************************************************************/
int nx_atomic_inc(volatile nxint32* value)
{
	return (int)_InterlockedIncrement((volatile LONG*)value);
}

/*************************************************************/
int nx_atomic_dec(volatile nxint32* value)
{
	return (int)_InterlockedDecrement((volatile LONG*)value);
}

/*************************************************************/
int nx_atomic_value(volatile nxint32* value)
{
	return (int)_InterlockedCompareExchange((volatile LONG*)value,0,0);
}
