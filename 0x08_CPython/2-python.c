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
 * print_python_bytes - print basic info about Python byte objects
 * @p: Python object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	char *s;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	size = PyBytes_Size(p);
    if (size < 10) 
        size++;
    else
    {
        size = 10;
    }
	s = PyBytes_AsString(p);
	printf("  size: %li\n"
	"  trying string: %s\n"
	"  first %li bytes:",
	size, s, size);
	
    for (i = 0; i <= size && i < 10; i++)
		printf(" %02hhx", s[i]);
	printf("\n");
}
