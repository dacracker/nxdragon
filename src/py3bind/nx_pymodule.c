#include "nx_pymodule.h"

/* NxKernel */
#	include "nx_pykernel_atomic.h"
#	include "nx_pykernel_list.h"


static struct PyModuleDef NxDragonModule = {
	PyModuleDef_HEAD_INIT,
	PY3BIND_MODULE_NAME,
	"Nexus Game Engine", /* Documentation */
	-1,
	0
};

/*************************************************************/
PyMODINIT_FUNC PyInit_NxDragon(void)
{
	PyObject *nxdragon_module;
	int index;

	struct {
		NX_BOOL (*init)();
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
