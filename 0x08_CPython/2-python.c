#include <Python.h>

/**
 * print_python_bytes - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	char *s;

	puts("[.] bytes object info");
	if (!PyBytes_Check(p))
	{
		puts("  [ERROR] Invalid Bytes Object");
		return;
	}

	size = (((PyVarObject *)(p))->ob_size);
	s = (((PyBytesObject *)(p))->ob_sval);

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", s);
	printf("  first %ld bytes:", size < 10 ? size + 1 : 10);

	for (i = 0; i <= size && i < 10; i++)
		printf(" %02hhx", s[i]);
	printf("\n");
}

/**
 * print_python_list - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t c;
	PyObject *item;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %li\n", ((PyListObject *) p)->allocated);
	printf("[*] Allocated = %li\n", Py_SIZE(p));
	for (c = 0; c < Py_SIZE(p); c++)
	{
		item = PyList_GET_ITEM(p, c);
		printf("Element %li: %s\n",
		c, item->ob_type->tp_name);
		if (PyBytes_Check(item))
			print_python_bytes(item);
	}
}
