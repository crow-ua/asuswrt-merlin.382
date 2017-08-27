
/* Python wrapper functions auto-generated by pidl */
#include <Python.h>
#include "includes.h"
#include <pytalloc.h>
#include "librpc/rpc/pyrpc.h"
#include "librpc/rpc/pyrpc_util.h"
#include "librpc/gen_ndr/ndr_dbgidl.h"
#include "librpc/gen_ndr/ndr_dbgidl_c.h"

staticforward PyTypeObject dbgidl_InterfaceType;

void initdbgidl(void);static PyTypeObject *ClientConnection_Type;

static bool pack_py_dummy_dbgidl_args_in(PyObject *args, PyObject *kwargs, struct dummy_dbgidl *r)
{
	const char *kwnames[] = {
		NULL
	};

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, ":dummy_dbgidl", discard_const_p(char *, kwnames))) {
		return false;
	}

	return true;
}

static PyObject *unpack_py_dummy_dbgidl_args_out(struct dummy_dbgidl *r)
{
	PyObject *result;
	result = Py_None;
	Py_INCREF(result);
	return result;
}

const struct PyNdrRpcMethodDef py_ndr_dbgidl_methods[] = {
	{ "dummy_dbgidl", "S.dummy_dbgidl() -> None", (py_dcerpc_call_fn)dcerpc_dummy_dbgidl_r, (py_data_pack_fn)pack_py_dummy_dbgidl_args_in, (py_data_unpack_fn)unpack_py_dummy_dbgidl_args_out, 0, &ndr_table_dbgidl },
	{ NULL }
};

static PyObject *interface_dbgidl_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_interface_init_helper(type, args, kwargs, &ndr_table_dbgidl);
}

#define PY_DOC_DBGIDL "Remote IDL debugger"
static PyTypeObject dbgidl_InterfaceType = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "dbgidl.dbgidl",
	.tp_basicsize = sizeof(dcerpc_InterfaceObject),
	.tp_doc = "dbgidl(binding, lp_ctx=None, credentials=None) -> connection\n"
"\n"
"binding should be a DCE/RPC binding string (for example: ncacn_ip_tcp:127.0.0.1)\n"
"lp_ctx should be a path to a smb.conf file or a param.LoadParm object\n"
"credentials should be a credentials.Credentials object.\n\n"PY_DOC_DBGIDL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = interface_dbgidl_new,
};

static PyMethodDef dbgidl_methods[] = {
	{ NULL, NULL, 0, NULL }
};

void initdbgidl(void)
{
	PyObject *m;
	PyObject *dep_samba_dcerpc_base;

	dep_samba_dcerpc_base = PyImport_ImportModule("samba.dcerpc.base");
	if (dep_samba_dcerpc_base == NULL)
		return;

	ClientConnection_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_base, "ClientConnection");
	if (ClientConnection_Type == NULL)
		return;

	dbgidl_InterfaceType.tp_base = ClientConnection_Type;

	if (PyType_Ready(&dbgidl_InterfaceType) < 0)
		return;
	if (!PyInterface_AddNdrRpcMethods(&dbgidl_InterfaceType, py_ndr_dbgidl_methods))
		return;

#ifdef PY_DBGIDL_PATCH
	PY_DBGIDL_PATCH(&dbgidl_InterfaceType);
#endif

	m = Py_InitModule3("dbgidl", dbgidl_methods, "dbgidl DCE/RPC");
	if (m == NULL)
		return;

	Py_INCREF((PyObject *)(void *)&dbgidl_InterfaceType);
	PyModule_AddObject(m, "dbgidl", (PyObject *)(void *)&dbgidl_InterfaceType);
#ifdef PY_MOD_DBGIDL_PATCH
	PY_MOD_DBGIDL_PATCH(m);
#endif

}