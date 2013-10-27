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

#include "nx_lua.h"

#include "nx_lua_list.h"

#include <stdio.h>

#include <lualib.h>
#include <lauxlib.h>

lua_State* _state = 0; 

/*************************************************************/
static void _nx_lua_init_libs(lua_State* state)
{
	/* Libs that ships with Lua */
	static const luaL_Reg libs[] = {
		{ "base", luaopen_base },
		{ LUA_LOADLIBNAME, luaopen_package },
		{0,0} /* sentinel */
	};

	const luaL_Reg *lib;

	void (*nxobjects[])(lua_State*) = {
		&_nx_bind_list,
		0
	};

	int index; 

	for(lib = libs; lib->func != 0; ++lib)
	{
		lib->func(state); 
		lua_settop(state,0); 
	}

	for(index = 0; nxobjects[index] != 0; ++index)
		(*nxobjects[index])(state); 
}

/*************************************************************/
static void _nx_lua_report_error(lua_State* state, int status)
{
	if(status != 0)
	{
		printf("Lua error: %s\n", lua_tostring(state,-1)); 

		/* Pop the error message */
		lua_pop(state,1); 
	}
}

/*************************************************************/
nxbool _nx_lua_setup(void)
{
	if(_state != 0)
		return nxfalse; 

	_state = luaL_newstate(); 

	if(!_state)
		return nxfalse; 

	/* Initialize Lua's base libraries */ 
	_nx_lua_init_libs(_state); 

	return nxtrue; 
}

/*************************************************************/
nxbool _nx_lua_shutdown(void)
{
	lua_close(_state); 

	return nxtrue; 
}

/*************************************************************/
lua_State* _nx_lua_state(void)
{
	return _state; 
}

/*************************************************************/
nxbool nx_lua_parse(const char *script)
{
	const int status = luaL_dostring(_state,script);

	_nx_lua_report_error(_state,status);

	return status == 0 ? nxtrue : nxfalse; 
}

/*************************************************************/
nxbool nx_lua_run(const char *filepath)
{
	const int status = luaL_dofile(_state,filepath);

	_nx_lua_report_error(_state,status);

	return status == 0 ? nxtrue : nxfalse; 
}
