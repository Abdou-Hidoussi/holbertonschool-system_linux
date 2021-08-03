#include <Python.h>
/**
 * print_python_list - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t c;

	printf("[*] Python list info\n"
	"[*] Size of the Python List = %li\n"
	"[*] Allocated = %li\n",
	Py_SIZE(p), ((PyListObject *) p)->allocated);
	for (c = 0; c < Py_SIZE(p); c++)
		printf("Element %li: %s\n", c, Py_TYPE((PyList_GetItem(p, c)))->tp_name);
}
