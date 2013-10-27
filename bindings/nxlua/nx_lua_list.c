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

#include "nx_lua_list.h"
#include "kernel/nx_list.h"

#include <stdlib.h>

#include <lauxlib.h>

#define NX_LUA_LIST_METATABLE "nx_list"
#define NX_LUA_LIST_PRIV_FIELD "_priv" 

/*************************************************************/
static int _nx_lua_list_new(lua_State *state)
{
	nx_list *list;

	/* Create a new lua table that will represent our Lua binding */
	lua_newtable(state); 
	luaL_getmetatable(state,NX_LUA_LIST_METATABLE); 
	lua_setmetatable(state,-2); 

	/* Allocate the _real_ list */
	list = lua_newuserdata(state,sizeof(nx_list));
	nx_list_init(list); 

	luaL_getmetatable(state,NX_LUA_LIST_METATABLE); 
	lua_setmetatable(state,-2); 

	/* Create a hidden field for our user data */
	lua_setfield(state,-2,NX_LUA_LIST_PRIV_FIELD);  

	return 1; 
}

/*************************************************************/
static int _nx_lua_list_delete(lua_State *state)
{
	nx_list *list;
	int index = 0; 

	luaL_checktype(state,1,LUA_TUSERDATA); 
	list = lua_touserdata(state,1); 

	for(index = 0; index < nx_list_size(list); ++index)
		luaL_unref(state,LUA_REGISTRYINDEX,(int)nx_list_at(list,index)); 

	nx_list_delete(list); 

	return 0;
}

/*************************************************************/
static int _nx_lua_list_size(lua_State *state)
{
	nx_list *list;

	luaL_checktype(state,1,LUA_TTABLE);

	lua_getfield(state,1,NX_LUA_LIST_PRIV_FIELD); 
	luaL_checktype(state,-1,LUA_TUSERDATA); 

	list = lua_touserdata(state,-1); 

	lua_pushinteger(state,nx_list_size(list)); 
	return 1;
}

/*************************************************************/
static int _nx_lua_list_append(lua_State *state)
{
	nx_list *list;
	void* ref; 

	luaL_checktype(state,1,LUA_TTABLE);

	lua_getfield(state,1,NX_LUA_LIST_PRIV_FIELD); 
	luaL_checktype(state,-1,LUA_TUSERDATA); 

	list = lua_touserdata(state,-1); 

	lua_pop(state,1); 

	/* Method arguments start at index 2 */
	lua_settop(state,2); 

	ref = (void*)luaL_ref(state, LUA_REGISTRYINDEX); 

	nx_list_append(list,ref); 

	return 0;
}

/*************************************************************/
static int _nx_lua_list_prepend(lua_State *state)
{
	nx_list *list;
	void* ref; 

	luaL_checktype(state,1,LUA_TTABLE);

	lua_getfield(state,1,NX_LUA_LIST_PRIV_FIELD); 
	luaL_checktype(state,-1,LUA_TUSERDATA); 

	list = lua_touserdata(state,-1); 

	lua_pop(state,1); 

	/* Method arguments start at index 2 */
	lua_settop(state,2); 

	ref = (void*)luaL_ref(state, LUA_REGISTRYINDEX); 

	nx_list_prepend(list,ref); 

	return 0;
}


/*************************************************************/
static int _nx_lua_list_value(lua_State *state)
{
	nx_list *list;
	int ref,
		index; 

	luaL_checktype(state,1,LUA_TTABLE);

	lua_getfield(state,1,NX_LUA_LIST_PRIV_FIELD); 
	luaL_checktype(state,-1,LUA_TUSERDATA); 

	list = lua_touserdata(state,-1); 

	luaL_checktype(state,2, LUA_TNUMBER); 
	index = lua_tointeger(state,2); 

	ref = (int)nx_list_value(list,index); 

	if(ref != 0) 
		lua_rawgeti(state, LUA_REGISTRYINDEX, ref); 
	else
		lua_pushinteger(state,0); 

	return 1;
}

/*************************************************************/
static int _nx_lua_list_remove_at(lua_State *state)
{
	nx_list *list;
	int ref,
		index; 

	luaL_checktype(state,1,LUA_TTABLE);

	lua_getfield(state,1,NX_LUA_LIST_PRIV_FIELD); 
	luaL_checktype(state,-1,LUA_TUSERDATA); 

	list = lua_touserdata(state,-1); 

	luaL_checktype(state,2, LUA_TNUMBER); 
	index = lua_tointeger(state,2); 

	ref = (int)nx_list_value(list,index); 

	if(ref != 0)
	{
		nx_list_remove_at(list,index); 
		luaL_unref(state,LUA_REGISTRYINDEX,ref);  
	}

	return 0;
}

/* NxList Methods */
static const luaL_Reg _nx_list_methods[] = {
	{ "new", &_nx_lua_list_new },
	{ "__gc",&_nx_lua_list_delete },
	{ "size", &_nx_lua_list_size },
	{ "append", &_nx_lua_list_append },
	{ "prepend", &_nx_lua_list_prepend,},
	{ "value", &_nx_lua_list_value },
	{ "remove_at", &_nx_lua_list_remove_at },
	{0,0}
};

/*************************************************************/
void _nx_bind_list(lua_State *state)
{
	luaL_newmetatable(state,NX_LUA_LIST_METATABLE);
	lua_pushstring(state,"__index");
	lua_pushvalue(state,-2);
	lua_settable(state,-3); 

	luaL_setfuncs(state,_nx_list_methods,0); 
	lua_setglobal(state,NX_LUA_LIST_METATABLE);
}
