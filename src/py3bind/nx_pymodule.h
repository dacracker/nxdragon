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
