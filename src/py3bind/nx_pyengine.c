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

#include "nx_pyengine.h"
#include "nx_pymodule.h"

/*************************************************************/
void nx_py3_init(void)
{
	PyImport_AppendInittab(PY3BIND_MODULE_NAME, PyInit_nxdragon);

	Py_Initialize();
}

/*************************************************************/
void nx_py3_shutdown(void)
{
	Py_Finalize();
} 

/*************************************************************/
void nx_py3_run_script(const char *script)
{
	PyRun_SimpleString(script);
}

/*************************************************************/
nxbool nx_py3_run_file(const char* filename)
{
	PyObject *py_filename;
	FILE *file;

	py_filename = Py_BuildValue("s",filename);

	if(!py_filename)
		return nxfalse;

	file = _Py_fopen(py_filename,"r+");

	if(file != 0)
	{
		PyRun_SimpleFile(file,filename);
		return nxtrue;
	}

	Py_DECREF(py_filename);

	return nxfalse;
}
