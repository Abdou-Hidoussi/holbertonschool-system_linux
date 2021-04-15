#ifndef SEARCH_ALGOS
#define SEARCH_ALGOS

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int _strcmp(char const *s1, char *s2);

void read_local_file(void);
void get_options(int argc, char const *argv[], int *options);
void read_files(int argc, char const *argv[], int *options);
void read_file(char const *name, int *options);
void error_file(char const *cmd);
void print_file(struct dirent *read, int *op);

#endif
