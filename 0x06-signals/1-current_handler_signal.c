#include "signals.h"
/**
 * current_handler_signal - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
void (*current_handler_signal(void))(int)
{
	void (*sig)(int) = NULL;

	sig = signal(SIGINT, print_hello);
	if (sig == SIG_ERR)
		return (NULL);

	return (sig);
}
