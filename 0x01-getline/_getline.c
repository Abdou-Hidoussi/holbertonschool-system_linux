#include "_getline.h"
/**
 * _strdup - duplicate a string
 * @str: the string to duplicate
 *
 * Return: string.
 */
char *_strdup(char *str)
{
	char *p;
	int i, j;


	if (str == NULL)
	{
		return (NULL);
	}


	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}


	p = malloc(i + 1 * sizeof(char));
	if (p == NULL)
	{
		return (NULL);
	}

	j = 0;
	while (j <= i)
	{
		p[j] = str[j];
		j++;
	}

	return (p);
}
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
 * _getline - 0
 *@fd: file .
 * Return: the line.
 */
char *_getline(const int fd)
{
	static list_t *head, *count;
	static int file;
	char *buffer, *new;
	list_t *line;
	int i = 0, j = 0;

	if (fd != file)
	{
		file = fd;
		buffer = malloc(sizeof(char *) * READ_SIZE);
		read(fd, buffer, READ_SIZE);
		line = malloc(sizeof(list_t));
		head = line;
		while (buffer[i])
		{
			if (buffer[i] == '\n' || buffer[i + 1] == '\000')
			{
				if (line->str)
					line = line->next = malloc(sizeof(list_t));
				line->str = malloc(sizeof(char *) * (i - j));
				_strncpy(line->str, buffer + j, i - j + 1);
				j = i + 1;
			}
			i++;
		}
		free(buffer);
		count = head;
	}
	else
	{
		if (head->next)
			head = head->next;
		else
		{
			free_count(count);
			return (NULL);
		}
	}
	new = _strdup(head->str);
	return (new);
}
/**
 * free_count - free the linked list
 *@count: head of the list .
 */
void free_count(list_t *count)
{
	list_t *line;

	while (count)
	{
		line = count->next;
		free(count->str);
		free(count);
		count = line;
	}
}
