#include "hls.h"
/**
 * count_flags - get ls options
 * @argc: argument count
 * @argv: arguments
 * @op: table of options
 * Return: list of names
 */
Node_t *count_flags(int argc, char const *argv[], int *op)
{
	int i = 1, j = 1;
	Node_t *files = NULL;

	while (i < argc)
	{
		if (argv[i][0] == '-' && _strlen(argv[i]) > 1)
		{
			j = 1;
			while (_strlen(argv[i]) > j)
			{
				switch (argv[i][j])
				{
				case '1':
					op[0] = 1;
					break;
				case 'l':
					op[1] = 1;
					break;
				case 'a':
					op[2] = 1;
					break;
				case 'A':
					op[3] = 1;
					break;
				default:
					break;
				}
				j++;
			}
		}
		else
		{
		   files = add_node(&files, argv[i]);
		}
		i++;
	}
	return (files);
}
