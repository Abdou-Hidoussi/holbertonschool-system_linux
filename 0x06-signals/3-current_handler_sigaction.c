#include "signals.h"
/**
 * current_handler_sigaction - retrieves the current
 * handler of the signal SIGINT
 *
 * Return: pointer to the current handler of SIGINT, or NULL on failure
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction sig;

	if (sigaction(SIGINT, NULL, &sig) > 0)
		return (sig.sa_handler);
	return (NULL);
}
