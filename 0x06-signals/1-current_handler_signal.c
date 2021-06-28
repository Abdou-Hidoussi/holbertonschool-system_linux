#include "signals.h"

void (*current_handler_signal(void))(int)
{
	void (*sig)(int) = NULL;

	sig = signal(SIGINT, print_hello);
	if (sig == SIG_ERR)
		return (NULL);

	return (sig);
}
