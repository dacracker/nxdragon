/*
	NxDragon Game Engine

	Author: Patrik Jeppsson <dacrackerx64@gmail.com>

	License: This source code is proprietary and may not
			 be used without permission from the author. 
*/

#include "nx_atomic.h"

/*
	This solution is based on the respective built-in
	functions in GCC. 
*/

/*************************************************************/
int nx_atomic_inc(volatile nxint32* value)
{
	return __sync_add_and_fetch(value,1);
}

/*************************************************************/
int nx_atomic_dec(volatile nxint32* value)
{
	return __sync_sub_and_fetch(value,1);
}

/*************************************************************/
int nx_atomic_value(volatile nxint32* value)
{
	return __sync_fetch_and_add(value,0);
}
