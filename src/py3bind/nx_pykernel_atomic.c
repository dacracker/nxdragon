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

#include "nx_pykernel_atomic.h"
#include "nx_pymodule.h"

#include "../kernel/nx_atomic.h"

#define PY3BIND_ATOMIC_TYPE "Atomic"

typedef struct {
	PyObject_HEAD
	int atomic_value; 
} nx_py_atomic;

/*************************************************************/
static PyObject* nx_py_atomic_new(PyTypeObject *type,PyObject *args, PyObject *kwds)
{
	/* Alloc memory for the object */
	nx_py_atomic *self = (nx_py_atomic*)type->tp_alloc(type,0);
	self->atomic_value = 0;

	NX_UNUSED(args)
	NX_UNUSED(kwds)

	return (PyObject*) self;
}

/*************************************************************/
static void nx_py_atomic_delete(nx_py_atomic *self)
{
	Py_TYPE(self)->tp_free((PyObject*)self);
}

/*************************************************************/
/* constructor */
static int nx_py_atomic_init(nx_py_atomic *self, PyObject *args, PyObject *kwds)
{
	static char* kwlist[] = { "value", 0 };

	/* It doesn't matter if the user doesn't supply a initial value */
	PyArg_ParseTupleAndKeywords(args,kwds, "|i",kwlist,&self->atomic_value);

	return 0;
}

/*************************************************************/
static PyObject* nx_py_atomic_value(nx_py_atomic *self)
{
	return PyLong_FromLong(nx_atomic_value(&self->atomic_value));
}

/*************************************************************/
static PyObject* nx_py_atomic_inc(nx_py_atomic *self)
{
	nx_atomic_inc(&self->atomic_value);

	Py_RETURN_NONE;
}

/*************************************************************/
static PyObject* nx_py_atomic_dec(nx_py_atomic *self)
{
	nx_atomic_dec(&self->atomic_value);
	
	Py_RETURN_NONE;
}

/* method table */
static PyMethodDef nx_py_atomic_methods[] = {
	{"value",(PyCFunction)nx_py_atomic_value, METH_NOARGS, "Reads the value atomically and returns the result" },
	{"inc",(PyCFunction)nx_py_atomic_inc, METH_NOARGS, "Increases the value atomically by 1"},
	{"dec",(PyCFunction)nx_py_atomic_dec, METH_NOARGS, "Decreases the value atomically by 1"},
	{0} /* sentinel */
};

/* Type infromation object */
static PyTypeObject nx_py_atomic_type = {
	PyVarObject_HEAD_INIT(0,0)
	PY3BIND_MODULE_NAME "." PY3BIND_ATOMIC_TYPE,
	sizeof(nx_py_atomic),
	0,
	(destructor) nx_py_atomic_delete,
	0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	Py_TPFLAGS_DEFAULT,
	"nxdragon Atomic type", /* documentation string */
	0,0,0,0,
	0,0,
	nx_py_atomic_methods, /* methods */
	0, /* members */
	0,0,0,0,
	0,0,
	(initproc)nx_py_atomic_init, /* init */
	0,
	nx_py_atomic_new
};

/*************************************************************/
nxbool _nx_pykernel_atomic_init(void)
{
	if(PyType_Ready(&nx_py_atomic_type) < 0)
		return nxfalse;

	return nxtrue;
}

/*************************************************************/
void _nx_pykernel_atomic_reg(PyObject *module)
{
	Py_INCREF(&nx_py_atomic_type);
	PyModule_AddObject(module, PY3BIND_ATOMIC_TYPE, (PyObject*)&nx_py_atomic_type); 
}
