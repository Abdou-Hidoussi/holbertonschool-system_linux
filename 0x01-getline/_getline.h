#ifndef L_FILE
#define L_FILE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define READ_SIZE 8192

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
char *str;
struct list_s *next;
} list_t;

char *_getline(const int fd);
void free_count(list_t *count);

char *_strdup(char *str);
char *_strncpy(char *dest, char *src, int n);


#endif
