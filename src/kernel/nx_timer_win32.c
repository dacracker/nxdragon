/***************************************************************************\
  This file is part of the NxDragon Game Engine.

  Copyright 2013 Patrik Jeppsson, Ulf Johnsson
  
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

#include "nx_timer.h"

#include "nx_types.h"
#include "nx_def.h"

#include <windows.h>

/*
	The current tick impl. on Windows systems
	is rather low res. I'll add a high res version
	if it turns out there's a need for it. 
*/

static DWORD _tick_start;

/*************************************************************/
nxuint32 nx_get_ticks(void) 
{
	return _tick_start - GetTickCount();
} 

/*************************************************************/
void nx_sleep(nxuint32 ms)
{
	Sleep(ms);
}

/*************************************************************/
void _nx_timer_init(void) 
{
	_tick_start = GetTickCount();
}
