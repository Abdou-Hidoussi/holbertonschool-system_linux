#include "hls.h"
/**
*_strlen - 0
*@s: char
*Return:: i
*/
int _strlen(char const *s)
{
	int i = 0;
	if (s != NULL)
	{
		while (*s != '\0')
		{
			s++;
			i++;
		}
	}

	return (i);
}
