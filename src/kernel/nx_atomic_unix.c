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
