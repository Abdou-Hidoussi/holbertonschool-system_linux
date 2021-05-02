#ifndef L_FILE
#define L_FILE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define READ_SIZE 8192



char *_getline(const int fd);

char *_strdup(char *str);
char *_strncpy(char *dest, char *src, int n);


/**
 * struct file_struct - singly linked list
 * @buffer: string - (malloc'ed string)
 * @fd: file.
 * @i: counter of characters.
 * @j: counter of characters.
 * @next: pointer to the next node;
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct file_struct
{
int fd;
int i;
int j;
char *buffer;
struct file_struct *next;
} file_struct_t;

#endif
