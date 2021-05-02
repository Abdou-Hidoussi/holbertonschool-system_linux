#include "_getline.h"

/**
*_strncpy - 0
*@dest: string
*@src: string
*@n: int
*Return: dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0' && src[i] != '\n'; ++i)
	{
		dest[i] = src[i];
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
/**
 * add_file - create new file
 *@fd: file .
 * Return: the new file.
 */
file_struct_t *add_file(int fd)
{
	file_struct_t *file;

	file = malloc(sizeof(file_struct_t));
	file->fd = fd;
	file->buffer = malloc(sizeof(char *) * READ_SIZE);
	read(fd, file->buffer, READ_SIZE);
	file->i = 0;
	file->j = 0;
	return (file);
}
/**
 * free_file - free the static variables
 *@h: head of the static variable .
 *@f: file .
 *@c: file .
 * Return: always NULL
 */
char *free_file(file_struct_t *h, file_struct_t **f, file_struct_t **c)
{
	file_struct_t *next;

	while (h != NULL)
	{
		next = (*h).next;
		free((*h).buffer);
		free(h);
		if (next == NULL)
			h = NULL;
		else
			h = next;
	}
	free(h);
	free(next);
	*f = NULL;
	*c = NULL;
	return (NULL);
}
/**
 * _getline - 0
 *@fd: file .
 * Return: the line.
 */
char *_getline(const int fd)
{
	static file_struct_t *file;
	file_struct_t *count = file;
	char *str;
	int i, j;


	if (!file)
	{
		file = add_file(fd);
		count = file;
	}
	else
	{
		while (count)
		{
			if (count->fd == fd)
				break;
			if (!count->next)
				count->next = add_file(fd);
			count = count->next;
		}
	}
	i = count->i;
	j = count->j;
	if (count->buffer[i] == '\000' || fd == -1)
		return (free_file(file, &file, &count));
	while (count->buffer[i])
	{
		if (count->buffer[i] == '\n' || count->buffer[i + 1] == '\000')
		{
			str = malloc(sizeof(char *) * (i - j));
			_strncpy(str, count->buffer + j, i - j + 1);
			j = i + 1;
			count->i = count->j = j;
			return (str);
		}
		i++;
	}
	return (NULL);
}
