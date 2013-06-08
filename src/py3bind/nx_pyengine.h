/*
    NxDragon Game Engine

    Author: Patrik Jeppsson <dacrackerx64@gmail.com>

    License: This source code is proprietary and may not
             be used without permission from the author. 
*/

#ifndef __NXPY3BIND_PYENGINE_H__
#define __NXPY3BIND_PYENGINE_H__

#include "nx_pydef.h"

/** \ingroup NxPy3Bind
  * \defgroup nx_pyengine nx_pyengine 
  * API for initialization and high-level
  * usage of the Python API. 
  * @{
  */

/** Initialize the Python 3 engine, must be called before all other Python functions! */ 
void NX_PY3BIND_API nx_py3_init();

/** Must be called when you're done using Python 3 to avoid resource leakage. */
void NX_PY3BIND_API nx_py3_shutdown(); 

/** @} */

#endif
