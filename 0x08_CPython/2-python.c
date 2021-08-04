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

	size = PyBytes_Size(p);
	s = PyBytes_AsString(p);

	printf("  size: %li\n", size);
	printf("  trying string: %s\n", s)
	if (size < 10)
		size += 1;
	else
	{
		size = 10;
	}
	printf("  first %li bytes:", size);

	for (i = 0; i <= size && i < 10; i++)
		printf(" %02hhx", s[i]);
	printf("\n");
}
