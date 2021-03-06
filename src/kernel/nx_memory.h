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

#ifndef __NX_KERNEL_MEMORY_H__
#define __NX_KERNEL_MEMORY_H__

#include <stdlib.h>

#define nx_malloc(size) malloc(size)
#define nx_free(ptr) free(ptr)

#define nx_realloc(ptr,size) realloc(ptr,size) 
#define nx_calloc(num,size) calloc(num,size)

#endif
