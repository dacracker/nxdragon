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

#ifndef __NXPY3BIND_KERNEL_ATOMIC__
#define __NXPY3BIND_KERNEL_ATOMIC__

#include "../kernel/nx_bool.h"

#include <Python.h>

/* Initializes types related to the atomic functions in NxKernel*/
nxbool _nx_pykernel_atomic_init(void);

/* Registers the types in the given module */
void _nx_pykernel_atomic_reg(PyObject *module);

#endif 
