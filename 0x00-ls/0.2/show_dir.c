#include "hls.h"

void show_dir(Node_t *files,int *op)
{
	Node_t *head = files;
	DIR *dir;
	struct dirent *read;

	while (head != NULL)
	{
		dir = opendir(head->str);
		if (dir != NULL)
		{
			while ((read = readdir(dir)) != NULL)
				printf("%s ", read->d_name);
			
		}
		head = head->next;
	}
}

