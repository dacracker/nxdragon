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

#ifndef __NX_KERNEL_LIBRARY_H__
#define __NX_KERNEL_LIBRARY_H__

/** \ingroup NxKernel
  * \defgroup nx_library nx_library
  * \brief Library object for lazy initialization of shared object files 
  * TODO
  * @{
  */

typedef struct nx_library_t nx_library; 

/** Attempts to load the library specified by path. A new library object is 
  * returned if the library could be loaded
  */
nx_library* nx_library_load(const char *path); 

/** Unloads a library and deallocates the library object. The library
  * object is invalid after this calls has been made. 
  */
void nx_library_unload(nx_library *self); 

/** Resolves a symbol from the provided library. The symbol can be
  * any visible function in the library. A invalid pointer (0)
  * is returned if the symbol could not be found. 
  */
void* nx_library_resolve(nx_library *self, const char *symbol); 

/** @} @} */

#endif
