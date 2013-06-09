#ifndef __NXPY3BIND_KERNEL_LIST__
#define __NXPY3BIND_KERNEL_LIST__

#include "../kernel/nx_bool.h"

#include <Python.h>

/* Initializes types related to the list object in NxKernel*/
NX_BOOL _nx_pykernel_list_init();

/* Registers the list types in the given module */
void _nx_pykernel_list_reg(PyObject *module);

#endif
