#include "_getline.h"
/**
 * parse - parse the lines.
 *@buffer: the buffer to parse.
 *@new_file: if its a new file
 * Return: the line.
 */
char *parse(char *buffer, int new_file)
{
	static int first, last;
	char *line;
	int count;

	count = 0;
	if (new_file)
		last = 0;
	first = last;
	if (buffer[last] == '\000')
	{
		free(buffer);
		return (NULL);
	}
	line = malloc(sizeof(char *) * READ_SIZE);
	while (buffer[last] != '\n' && buffer[last] != '\000')
	{
		last++;
		count++;
	}

	strncpy(line, buffer + first, count);
	last++;
	first++;
	return (line);
}
/**
 * _getline - 0
 *@fd: file .
 * Return: the line.
 */
char *_getline(const int fd)
{
	static char *buffer;
	char *tmp;
	static int file, count;

	if (fd != file || count >= READ_SIZE)
	{
		file = fd;
		buffer = malloc(sizeof(char *) * READ_SIZE);
		read(fd, buffer, READ_SIZE);
		count = 0;
		tmp = strdup(buffer);
		tmp = parse(tmp, 1);
		if (tmp != NULL)
			count += strlen(tmp) + 1;
		if (buffer[0] == '\000')
			return (NULL);
		return (tmp);
	}
	tmp = strdup(buffer);
	tmp = parse(tmp, 0);
	if (tmp != NULL)
		count += strlen(tmp) + 1;

	return (tmp);
}
