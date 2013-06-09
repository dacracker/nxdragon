#ifndef __NXPY3BIND_KERNEL_ATOMIC__
#define __NXPY3BIND_KERNEL_ATOMIC__

#include "../kernel/nx_bool.h"

#include <Python.h>

/* Initializes types related to the atomic functions in NxKernel*/
NX_BOOL _nx_pykernel_atomic_init();

/* Registers the types in the given module */
void _nx_pykernel_atomic_reg(PyObject *module);

#endif 
