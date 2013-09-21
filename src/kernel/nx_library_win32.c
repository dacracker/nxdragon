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

#include "nx_library.h"
#include "nx_compiler.h"
#include "nx_memory.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

struct nx_library_t {
	HMODULE handle; 
};

/*************************************************************/
struct nx_library_t* nx_library_load(const char *path)
{
	struct nx_library_t *lib = nx_malloc(sizeof(struct nx_library_t));
	lib->handle = LoadLibrary(path);

	if(lib->handle != 0)
		return lib;

	nx_free(lib);
	return 0;
}

/*************************************************************/
void nx_library_unload(struct nx_library_t *self)
{
	FreeLibrary(self->handle);
	nx_free(self);
}

#ifdef NX_CC_MSVC
#	pragma warning(disable:4054)
#endif

/*************************************************************/
void* nx_library_resolve(struct nx_library_t *self, const char *symbol)
{
	return (void*)GetProcAddress(self->handle,symbol);
}
