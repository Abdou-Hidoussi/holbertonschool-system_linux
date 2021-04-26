#include "_getline.h"

char *parse(char *buffer)
{
	static int first, last;
	char *line;
	int count;

	count = 0;
	first = last;
	if (buffer[last] == '\000')
	{
		free(buffer);
		return NULL;
	}
	line = malloc(sizeof(char *) * READ_SIZE);
	while (buffer[last] != '\n'&& buffer[last] != '\000')
	{
		last++;
		count++;  
	}

	strncpy(line, buffer + first , count);
	last++;
	first++;
	return line;
	
}
char *_getline(const int fd)
{
	static char *buffer;
	char *tmp;
	static int file;

	if (fd != file)
	{
		file = fd;
		buffer = malloc(sizeof(char *) * READ_SIZE);
		read(fd, buffer, READ_SIZE);
		if(buffer[0] == '\000')
			return NULL;
		
	}
	tmp = strdup(buffer);
	tmp = parse(tmp);    
	return tmp;
}
