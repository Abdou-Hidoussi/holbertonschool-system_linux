#include "hls.h"
/**
 * read_local_file - process local file
 */
void read_local_file(void)
{
	DIR *dir;
	struct dirent *read;

	dir = opendir(".");
	if (dir)
	{
		while ((read = readdir(dir)) != NULL)
		{
			printf("%s ", (*read).d_name);
		}
		printf("\n");
		closedir(dir);
	}
}
