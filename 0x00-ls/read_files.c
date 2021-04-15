#include "hls.h"
/**
 * read_files - check file names
 * @argc: argument count
 * @argv: arguments
 * @op: table of options
 */
void read_files(int argc, char const *argv[], int *op)
{
	int i = 1;

	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			read_file(argv[0], argv[i], op);
		}
		if ((i + 1) != argc)
			printf("\n");
		i++;
	}
}
/**
 * read_file - check file names
 * @pname: name of program
 * @name: name of files
 * @op: table of options
 */
void read_file(char const *pname, char const *name, int *op)
{
	DIR *dir;
	struct dirent *read;

	dir = opendir(name);
	if (dir != NULL)
	{
		if (op[4] == 1)
			printf("%s:\n", name);
		read = readdir(dir);
		while (read != NULL)
		{
			if ((*read).d_name[0] != '.')
			{
				printf("%s ", (*read).d_name);
				if (op[0] == 1)
					printf("\n");
			}
			else
			{
				if (op[1] == 1)
				{
					printf("%s ", (*read).d_name);
					if (op[0] == 1)
						printf("\n");
				}
			}
			read = readdir(dir);
		}
		printf("\n");
	}
	if (errno != 0)
		error_file(pname, name);
	closedir(dir);
}
