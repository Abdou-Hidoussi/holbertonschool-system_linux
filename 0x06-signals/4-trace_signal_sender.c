#include "signals.h"

void term_handle(int sig, siginfo_t *sig_info, void *p)
{
	(void)p;
	(void)sig;
	printf("SIGQUIT sent by %d\n", sig_info->si_pid);
}

int trace_signal_sender(void)
{
	struct sigaction new, old;

	new.sa_sigaction = term_handle;
	sigemptyset(&new.sa_mask);
	new.sa_flags = 0;

	return (sigaction(SIGQUIT, &new, &old));
}
