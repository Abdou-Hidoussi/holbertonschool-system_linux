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
	char *py_bytes_str;
	Py_ssize_t py_bytes_size;
	Py_ssize_t i;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	py_bytes_size = (((PyVarObject *)(p))->ob_size);
	py_bytes_str = (((PyBytesObject *)(p))->ob_sval);

	printf("  size: %ld\n", py_bytes_size);
	printf("  trying string: %s\n", py_bytes_str);
	py_bytes_size = py_bytes_size > 9 ? 10 : py_bytes_size + 1;
	printf("  first %ld bytes: ", py_bytes_size);

	for (i = 0; i < py_bytes_size; i++)
		printf("%02hhx%c", py_bytes_str[i], i < py_bytes_size - 1 ? ' ' : '\n');
}
