#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


int handle_signal(void);
void (*current_handler_signal(void))(int);
void print_hello(int sig);
void set_print_hello(void);

#endif /* SIGNALS_H */