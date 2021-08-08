#include <Python.h>
#include <object.h>
#include <unicodeobject.h>
#include <stdio.h>
/**
 * print_python_string - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_string(PyObject *p)
{

	wchar_t *value;
	Py_ssize_t len;

	printf("[.] string object info\n");
	if (strncmp(p->ob_type->tp_name, "str", 3) != 0)
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}
	len = ((PyASCIIObject *)(p))->length;
	value = PyUnicode_AsWideCharString(p, &len);

	if (PyUnicode_IS_COMPACT_ASCII(p) != 0)
		printf("  type: compact ascii\n  length: %lu\n  value: %ls\n",
		len, value);
	else
		printf("  type: compact unicode object\n  length: %lu\n  value: %ls\n",
		len, value);
}
