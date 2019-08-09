#include <Python.h>

using namespace std;


PyObject* test(PyObject* self, PyObject* args)
{
	/*int a = 0;
	int b = 0;

	if (!PyArg_ParseTuple(args, "ii", &a, &b))
	{
		return nullptr;
	}*/
	//printf("utils test: %s + %s = %s", a, b, a + b);
	printf("dddddddddddddddd\n");
	Py_RETURN_TRUE;

}

static PyMethodDef utils_methods[] = {
	{ "test",		(PyCFunction)test,		METH_VARARGS, "" },
	{ NULL, NULL }  /* Sentinel */
};

static PyTypeObject * py_adder_type = NULL;

template<class PY_TYPE>
PyObject* add(PyObject *self, PyObject *args)
{
	PY_TYPE* py_obj = (PY_TYPE*)self;

	int a = 0;
	int b = 0;

	if (!PyArg_ParseTuple(args, "ii", &a, &b))
	{
		return nullptr;
	}

	printf("%s + %s = %s", a, b, a + b);
	return nullptr;
}

class py_adder
{

};

static PyMethodDef py_adder_methods[] = {
	{ "add",	(PyCFunction)add<py_adder>,	METH_VARARGS, "" },
	{ NULL, NULL } /* Sentinel */
};


bool init_py_adder(PyObject *module)
{
	static PyTypeObject type = {
		PyObject_HEAD_INIT(&PyType_Type)
		0,								// ob_size 
		"adder",					    // tp_name
		sizeof(py_adder),				// tp_basicsize
		0,								// tp_itemsize
		0,		// tp_dealloc
		0,								// tp_print
		0,								// tp_getattr
		0,								// tp_setattr
		0,								// tp_compare
		0,			// tp_repr
		0,								// tp_as_number
		0,								// tp_as_sequence
		0,								// tp_as_mapping
		0,								// tp_hash
		0,								// tp_call
		0,			// tp_str
		0,			// tp_getattro
		0,			// tp_setattro
		0,								// tp_as_buffer
		Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE ,	// tp_flags
		0,								// tp_doc
		0,								// tp_traverse
		0,								// tp_clear
		0,								// tp_richcompare
		0,								// tp_weaklistoffset
		0,								// tp_iter
		0,								// tp_iternext
		py_adder_methods,			    // tp_methods
		0,								// tp_members
		0,								// tp_getset
		0,								// tp_base
		0,								// tp_dict
		0,								// tp_descr_get
		0,								// tp_descr_set
		0,								// tp_dictoffset
		0,                              // tp_init
		0,								// tp_alloc
		0,								// tp_new
	};

	type.tp_new = PyType_GenericNew;
	py_adder_type = &type;
	Py_INCREF(py_adder_type);
	PyModule_AddObject(module, "adder", (PyObject *)py_adder_type);
	return true;
}


void init_utils()
{
	PyObject *module = Py_InitModule3("my_utils", utils_methods,"Module utils");
	//init_py_adder(module);

	/*
	#define PY_MOUDLE_ADD_STRING(moudle, TAG) PyModule_AddStringConstant(moudle, #TAG, TAG)
	#define PY_MOUDLE_ADD_INT(moudle, TAG) PyModule_AddIntConstant(moudle, #TAG, TAG)
	#define PY_MOUDLE_ADD_ENUM(moudle, ENUM_CLASS, ENUM_VAL) PyModule_AddIntConstant(moudle, #ENUM_VAL, int(ENUM_CLASS::ENUM_VAL))
	PY_MOUDLE_ADD_STRING(module, "qbh");
	PY_MOUDLE_ADD_ENUM
	PyModule_AddIntConstant
	PY_MOUDLE_ADD_INT(module, TEST_INT);*/




}


