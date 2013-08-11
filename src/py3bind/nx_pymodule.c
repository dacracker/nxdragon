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

#include "nx_pymodule.h"

/* NxKernel */
#	include "nx_pykernel_atomic.h"
#	include "nx_pykernel_list.h"


static struct PyModuleDef NxDragonModule = {
	PyModuleDef_HEAD_INIT,
	PY3BIND_MODULE_NAME,
	"NxDragon Game Engine", /* Documentation */
	-1,
	0
};

/*************************************************************/
PyMODINIT_FUNC PyInit_nxdragon(void)
{
	PyObject *nxdragon_module;
	int index;

	struct {
		NX_BOOL (*init)(void);
		void (*reg)(PyObject *module);
	} nxdragon_types[] =
	{
		/* Atomic */		
		{ _nx_pykernel_atomic_init, _nx_pykernel_atomic_reg },
		/* List */
		{ _nx_pykernel_list_init, _nx_pykernel_list_reg }
	};

	/* Initialize all types */
	for(index = 0; index < sizeof(nxdragon_types)/sizeof(nxdragon_types[0]); ++index)
		if(!(*nxdragon_types[index].init)())
			return 0;

	nxdragon_module = PyModule_Create(&NxDragonModule);

	if(!nxdragon_module)
		return 0;
	
	for(index = 0; index < sizeof(nxdragon_types)/sizeof(nxdragon_types[0]); ++index)
		(*nxdragon_types[index].reg)(nxdragon_module);

	return nxdragon_module;
}
