/*
    NxDragon Game Engine

    Author: Patrik Jeppsson <dacrackerx64@gmail.com>

    License: This source code is proprietary and may not
             be used without permission from the author. 
*/

#include "nx_pyengine.h"

#include <Python.h>

/*************************************************************/
void nx_py3_init()
{
	Py_Initialize();
}

/*************************************************************/
void nx_py3_shutdown()
{
	Py_Finalize();
} 
