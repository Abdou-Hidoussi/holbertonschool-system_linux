#include "signals.h"
/**
 * sigcall - print the signal
 * @sig: the signal
 */
void sigcall(int sig)
{
	printf("Gotcha! [%i]\n", sig);
	fflush(stdout);
}
/**
 * handle_sigaction - set a handler for the signal SIGINT
 *
 * Return: -1 or 0
 */
int handle_sigaction(void)
{
	struct sigaction new_sig;

	new_sig.sa_handler = sigcall;
	return (sigaction(SIGINT, &new_sig, NULL));
}
