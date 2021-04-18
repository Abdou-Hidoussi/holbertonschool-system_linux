#ifndef SEARCH_ALGOS
#define SEARCH_ALGOS

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <stdint.h>
#include <time.h>
/**
 * struct Node - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct Node
{
char *str;
unsigned int len;
struct Node *next;
} Node_t;

int _strcmp(char const *s1, char *s2);
char *_strncpy(char *dest, char const *src, int n);
int _strlen(char const *s);
char *_strcpy(char *dest, char const *src);


Node_t *add_node(Node_t **head, const char *str);
void free_list(Node_t *h);

Node_t *count_flags(int argc, char const *argv[], int *op);
void show_dir(Node_t *files, int *op);
void show_op(Node_t *head, int *op, int mult);
void show_local(char *head, int *op);
void condition_overload(struct dirent *read, int *op);
void long_format(struct dirent *read);
void print_1(char *read, int *op);

void error_file(char const *cmd);



#endif
