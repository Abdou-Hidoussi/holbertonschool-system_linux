#include "signals.h"

/**
 * print_hello - handler for the signal SIGINT
 * @sig: signal number
 */
void print_hello(int sig)
{
	printf("signal : %d \n", sig);
}

/**
 * set_print_hello - a function that set a handler for the signal SIGINT
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
