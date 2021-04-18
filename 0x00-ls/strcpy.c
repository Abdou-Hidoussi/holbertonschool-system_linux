#include "hls.h"
/**
*_strcpy - 0
*@src: src
*@dest: dest
*Return: dest
*/
char *_strcpy(char *dest, char const *src)
{
	int i = 0, j;

	while (src[i] != '\0')
	{
		i++;
	}

	j = 0;
	while (j <= i)
	{
		dest[j] = src[j];
		j++;
	}
	return (dest);
}
