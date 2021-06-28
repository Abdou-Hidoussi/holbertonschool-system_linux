#include "signals.h"
/**
 * sigcall - call signal
 * @sig: the recived signal
 */
void sigcall(int sig)
{
	printf("Gotcha! [%i]\n", sig);
	fflush(stdout);
}
/**
 * handle_signal - set a handler for the signal SIGINT
 * Return: -1 or 1
 */
int handle_signal(void)
{
	if (signal(SIGINT, sigcall) == SIG_ERR)
		return (-1);
	return (0);
}
