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
			read_file(argv[i], op);
		}
		if ((i + 1) != argc && op[0] == 0 && op[3] == 0)
			printf("\n");
		if ((i + 2) < argc && (op[0] == 1 || op[1] == 1 || op[2] == 1 || op[3] == 1))
			printf("\n");
		i++;
	}
}
/**
 * read_file - check file names
 * @name: name of files
 * @op: table of options
 */
void read_file(char const *name, int *op)
{
	DIR *dir;
	struct dirent *read;

	dir = opendir(name);
	if (dir != NULL)
	{
		if (op[4] > 2)
			printf("%s:\n", name);
		read = readdir(dir);
		while (read != NULL)
		{
			if ((*read).d_name[0] != '.')
			{
				print_file(read, op);
			}
			else
			{
				if (op[1] == 1)
				{
					print_file(read, op);
				}
				else
				{
					if (op[2] == 1 && _strcmp((*read).d_name, ".")
						&& _strcmp((*read).d_name, ".."))
					{
						print_file(read, op);
					}
				}
			}
			read = readdir(dir);
		}
		if (op[0] == 0 && op[1] == 0 && op[2] == 0 && op[3] == 0)
			printf("\n");
	}
	if (errno != 0)
		error_file(name);
	closedir(dir);
}
/**
 * print_file - print the file
 * @read: the file
 * @op: table of options
 */
void print_file(struct dirent *read, int *op)
{
	struct stat fileStat;
	struct group *grp;
	struct passwd *user;
	char time[24];

	if (op[3] == 1)
	{
		_strncpy(time, ctime(&fileStat.st_mtime), 24);
		lstat((*read).d_name, &fileStat);
		printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
		printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
		printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
		printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
		printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
		printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
		printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
		printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
		printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
		printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
		user = getpwuid(fileStat.st_uid);
		grp = getgrgid(fileStat.st_gid);
		printf(" %lu %s %s %li %s %s\n", fileStat.st_nlink, (*user).pw_name,
		(*grp).gr_name, (intmax_t)fileStat.st_size, time, (*read).d_name);
	}
	else
		printf("%s ", (*read).d_name);
	if (op[0] == 1)
		printf("\n");
}
