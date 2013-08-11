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
  
#ifndef __NXPY3BIND_PYMODULE_H__
#define __NXPY3BIND_PYMODULE_H__

#include <Python.h>
#include "../kernel/nx_compiler.h"

#define PY3BIND_MODULE_NAME "nxdragon"

PyMODINIT_FUNC PyInit_nxdragon(void);

#ifdef NX_CC_MSVC
#	pragma warning(disable:4127) /* Disables "Conditional expression is constant" emitted from Py_XDECREF() */
#endif

#endif
