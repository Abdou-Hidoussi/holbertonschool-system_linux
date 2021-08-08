#include <Python.h>
/**
 * print_python_int - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_int(PyObject *p)
{
	unsigned long value = 0;
	Py_ssize_t size, i, pos;
	digit *num;


	if (PyLong_Check(p) == 0 || p == NULL)
	{
		printf("Invalid Int Object\n");
		return;
	}

	num = ((PyLongObject *)(p))->ob_digit;
	size = ((PyVarObject *)(p))->ob_size;
    pos = abs(size);


	if (pos > 3 || (pos == 3 && num[2] > 15))
	{
		printf("C unsigned long int overflow\n");
		return;
	}

	for (i = 0; i < pos; i++)
		value += num[i] * (1L << (i * PyLong_SHIFT));

	if (size < 0)
		printf("-");

	printf("%lu\n", value);
}
