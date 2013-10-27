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

#ifndef __NX_LUA_H__
#define __NX_LUA_H__

#include "nx_def.h"
#include "kernel/nx_bool.h"

/** Initializes the script engine and binds all compiled NxDragon modules */
nxbool _nx_lua_setup(void); 

/** Shuts down the script engine and frees all the related memory */
nxbool _nx_lua_shutdown(void); 

/** Returns the global lua state */
struct lua_State* _nx_lua_state(void); 

/** Parses the given string as a Lua script */
NX_LUA_API nxbool nx_lua_parse(const char *script);

/** Parses the given file as a Lua script */
NX_LUA_API nxbool nx_lua_run(const char *filepath);  

#endif
