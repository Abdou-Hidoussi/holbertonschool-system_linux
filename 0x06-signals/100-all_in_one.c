#include "signals.h"
/**
 * handler - sets up a single handler for all the signals
 * @sig: signal count
 * @info: pointer to the siginfo_t
 * @ucontext: pointer to the context that will be resumed
 */
void handler(int sig, siginfo_t *info, void *ucontext)
{
	(void) sig;
	(void) ucontext;
	psiginfo(info, "Caught");
}
/**
 * all_in_one - Handel all signals
 */
void all_in_one(void)
{
	int i;
	struct sigaction sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handler;
	for (i = 1; i <= SIGRTMAX; i++)
		sigaction(i, &sig, NULL);
}
