#include "hls.h"
/**
 * main - Main ls
 * @argc: argument count
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char const *argv[])
{
	int op[5] = {0, 0, 0, 0, 0};

	if (argc == 1)
	{
		read_local_file();
	}
	else
	{
		get_options(argc, argv, op);
		read_files(argc, argv, op);
	}

	return (0);
}
