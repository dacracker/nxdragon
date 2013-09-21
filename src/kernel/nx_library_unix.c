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

#include "nx_library.h"
#include "nx_memory.h"

#include <dlfcn.h>

#include <stdio.h>

struct nx_library_t {
    void *handle; 
};

/*************************************************************/
struct nx_library_t* nx_library_load(const char *path)
{
    struct nx_library_t *library = nx_malloc(sizeof(struct nx_library_t));
    library->handle = dlopen(path, RTLD_LAZY);

    if(library->handle != 0)
        return library;
    
    nx_free(library);
    return 0;
}

/*************************************************************/
void nx_library_unload(struct nx_library_t *self)
{
    dlclose(self->handle);

    nx_free(self);   
}

/*************************************************************/
void* nx_library_resolve(struct nx_library_t *self, const char *symbol)
{
    void *dlsymbol;

    /* clear the error stack */
    dlerror();

    /* attempt to find the symbol */
    dlsymbol = dlsym(self->handle, symbol);

    /* check for errors */
    if(dlerror() == 0)
        return dlsymbol;

    return 0;
}
