#include <Python.h>
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
/**
 * print_python_bytes - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_bytes(PyObject *p)
{
	char *s;
	Py_ssize_t size, i;

	setbuf(stdout, NULL);
	printf("[.] bytes object info\n");
	if (!p || !PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	size = (((PyVarObject *)(p))->ob_size);
	s = (((PyBytesObject *)(p))->ob_sval);

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", s);
	size = size > 9 ? 10 : size + 1;
	printf("  first %ld bytes: ", size);

	for (i = 0; i < size; i++)
		printf("%02hhx%c", s[i], i <= size ? ' ' : '\n');
}

/**
 * print_python_list - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_list(PyObject *p)
{
	PyObject *item;
	Py_ssize_t size, i;

	setbuf(stdout, NULL);
	if (!p || !PyList_Check(p))
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}

	size = (((PyVarObject *)(p))->ob_size);
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; i++)
	{
		item = ((PyListObject *)(p))->ob_item[i];
		printf("Element %ld: %s\n", i, item->ob_type->tp_name);
		if (PyBytes_Check(item))
			print_python_bytes(item);
		else if (PyFloat_Check(item))
			print_python_float(item);
	}
}
