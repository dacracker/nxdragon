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

#ifndef __NXPY3BIND_PYENGINE_H__
#define __NXPY3BIND_PYENGINE_H__

#include "nx_def.h"
#include "../kernel/nx_bool.h"

/** \ingroup NxPy3Bind
  * \defgroup nx_pyengine nx_pyengine 
  * API for initialization and high-level
  * usage of the Python API. 
  * @{
  */

/** Initialize the Python 3 engine, must be called before all other Python functions! */ 
void NX_PY3BIND_API nx_py3_init(void);

/** Must be called when you're done using Python 3 to avoid resource leakage. */
void NX_PY3BIND_API nx_py3_shutdown(void); 

/** Runs the given Python 3 script */
void NX_PY3BIND_API nx_py3_run_script(const char *script);

/** Opens the file and treats it's content as a Python 3 script */
nxbool NX_PY3BIND_API nx_py3_run_file(const char* filename);

/** @} */

#endif
