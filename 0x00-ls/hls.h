#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>


void read_local_file();
void get_options(int argc, char const *argv[], int *options);
void read_files(int argc, char const *argv[], int *options);
void read_file(char const *name, int *options);