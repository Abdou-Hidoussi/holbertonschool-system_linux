#include "hls.h"
/**
 * get_options - get ls options
 * @argc: argument count
 * @argv: arguments
 * @op: table of options
 */
void get_options(int argc, char const *argv[], int *op)
{
	int i = 0;

	while (i < argc)
	{
		if (!_strcmp(argv[i], "-1"))
		{
			op[0] = 1;
		}
		if (!_strcmp(argv[i], "-a"))
		{
			op[1] = 1;
		}
		if (!_strcmp(argv[i], "-A"))
		{
			op[2] = 1;
		}
		if (!_strcmp(argv[i], "-l"))
		{
			op[3] = 1;
		}
		if (argv[i][0] != '-')
		{
			op[4] = 1;
		}
		i++;
	}
}
