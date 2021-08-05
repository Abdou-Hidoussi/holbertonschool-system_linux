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
 * print_python_float - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_float(PyObject *p)
{
	char *s;
	double value;

	setbuf(stdout, NULL);

	printf("[.] float object info\n");
	if (!p || !PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}

	value = (((PyFloatObject *)(p))->ob_fval);
	s = PyOS_double_to_string(value, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
	printf("  value: %s\n", s);
}
