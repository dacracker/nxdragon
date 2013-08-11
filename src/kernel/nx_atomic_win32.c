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
