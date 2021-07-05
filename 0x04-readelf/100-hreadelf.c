#include "elf.h"
/**
 * main - read elf
 * @argc: the count of args
 * @argv: the args
 * @env: environment
 * Return: -1 or 0
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/readelf", "-W", "-s", "", NULL};

	(void)argc;
	args[3] = argv[1];
	if (execve("/usr/bin/readelf", args, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
