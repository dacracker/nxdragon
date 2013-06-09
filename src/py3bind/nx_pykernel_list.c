#include "nx_pykernel_list.h"
#include "nx_pymodule.h"

#include "../kernel/nx_list.h"

#define PY3BIND_LIST_TYPE "List"

typedef struct {
	PyObject_HEAD
	nx_list list;  
} nx_py_list;

/*************************************************************/
static PyObject* nx_py_list_new(PyTypeObject *type,PyObject *args, PyObject *kwds)
{
	/* Alloc memory for the object */
	nx_py_list *self = (nx_py_list*)type->tp_alloc(type,0);

	self = (nx_py_list*)type->tp_alloc(type,0);

	NX_UNUSED(args)
	NX_UNUSED(kwds)

	return (PyObject*) self;
}

/*************************************************************/
static void nx_py_list_delete(nx_py_list *self)
{
	nx_list_delete(&self->list);
	Py_TYPE(self)->tp_free((PyObject*)self);
}

/*************************************************************/
/* constructor */
static int nx_py_list_init(nx_py_list *self, PyObject *args, PyObject *kwds)
{
	/* Initialize the internal list */
	nx_list_init(&self->list);

	NX_UNUSED(args);
	NX_UNUSED(kwds);

	return 0;
}

/*************************************************************/
/* Binding for nx_list_size() */
static PyObject* nx_py_list_size(nx_py_list *self)
{
	return PyLong_FromLong(nx_list_size(&self->list));
}

/*************************************************************/
/* Binding for nx_list_insert() */
static PyObject* nx_py_list_insert(nx_py_list *self, PyObject *args)
{
	int index;
	PyObject *data;

	index = 0;
	data = 0;

	if(!PyArg_ParseTuple(args,"iO",&index,&data))
		goto end;

	Py_INCREF(data);
	nx_list_insert(&self->list,index,data);

	end:
	Py_RETURN_NONE;
}

/*************************************************************/
/* Binding for nx_list_value() */
static PyObject* nx_py_list_value(nx_py_list *self, PyObject *args)
{
	int index;
	PyObject *data;

	index = 0;

	if(!PyArg_ParseTuple(args,"i",&index))
		goto end;

	 if((data = nx_list_value(&self->list,index)) != 0)
		 return data;

	end:
	Py_RETURN_NONE;
}

/* method table */
static PyMethodDef nx_py_list_methods[] = {
	{"size",(PyCFunction)nx_py_list_size, METH_NOARGS, "Returns the current size of the list" },
	{"insert",(PyCFunction)nx_py_list_insert, METH_VARARGS , "Inserts a new value into the list" },
	{"value",(PyCFunction)nx_py_list_value, METH_VARARGS , "Returns the value of the given index, if any" },
	{0} /* sentinel */
};

/* Type infromation object */
static PyTypeObject nx_py_list_type = {
	PyVarObject_HEAD_INIT(0,0)
	PY3BIND_MODULE_NAME "." PY3BIND_LIST_TYPE,
	sizeof(nx_py_list),
	0,
	(destructor) nx_py_list_delete,
	0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	Py_TPFLAGS_DEFAULT,
	"nxdragon List type", /* documentation string */
	0,0,0,0,
	0,0,
	nx_py_list_methods, /* methods */
	0, /* members */
	0,0,0,0,
	0,0,
	(initproc)nx_py_list_init, /* init */
	0,
	nx_py_list_new
};

/*************************************************************/
NX_BOOL _nx_pykernel_list_init()
{
	if(PyType_Ready(&nx_py_list_type) < 0)
		return NX_FALSE;

	return NX_TRUE;
}

/*************************************************************/
void _nx_pykernel_list_reg(PyObject *module)
{
	Py_INCREF(&nx_py_list_type);
	PyModule_AddObject(module, PY3BIND_LIST_TYPE, (PyObject*)&nx_py_list_type);
}
