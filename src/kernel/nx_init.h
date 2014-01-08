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

#ifndef __NX_KERNEL_INIT_H__
#define __NX_KERNEL_INIT_H__

#include "nx_def.h"
#include "nx_types.h"

/** Initializes the kernel module */
NX_KERNEL_API nxbool nx_kernel_init(void);  

/** Shuts down the kernel module */
NX_KERNEL_API void nx_kernel_shutdown(void); 

#endif 
