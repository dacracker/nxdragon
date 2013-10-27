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

#include "kernel/nx_def.h"
#include "nxlua/nx_init.h"
#include "nxlua/nx_lua.h"

int main(int args, char **argv)
{
	NX_UNUSED(args); 
	NX_UNUSED(argv); 

	/** Initialize the Lua module */
	if(!nx_lua_init())
		return 1; 
	
	/** Run a Lua script */
	if(!nx_lua_run("hello.lua"))
		return 2; 

	/** Shutdown the Lua module */
	if(!nx_lua_shutdown())
		return 3; 

	return 0;
}
