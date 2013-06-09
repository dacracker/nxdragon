/*
    NxDragon Game Engine

    Author: Patrik Jeppsson <dacrackerx64@gmail.com>

    License: This source code is proprietary and may not
             be used without permission from the author. 
*/

#include "nx_pyengine.h"
#include "nx_pymodule.h"

/*************************************************************/
void nx_py3_init()
{
	PyImport_AppendInittab(PY3BIND_MODULE_NAME, PyInit_NxDragon);

	Py_Initialize();
}

/*************************************************************/
void nx_py3_shutdown()
{
	Py_Finalize();
} 

/*************************************************************/
void nx_py3_run_script(const char *script)
{
	PyRun_SimpleString(script);
}

/*************************************************************/
NX_BOOL nx_py3_run_file(const char* filename)
{
	PyObject *py_filename;
	FILE *file;

	py_filename = Py_BuildValue("s",filename);

	if(!py_filename)
		return NX_FALSE;

	file = _Py_fopen(py_filename,"r+");

	if(file != 0)
	{
		PyRun_SimpleFile(file,filename);
		return NX_TRUE;
	}

	Py_DECREF(py_filename);

	return NX_FALSE;
}