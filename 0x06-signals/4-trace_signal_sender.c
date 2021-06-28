#include "signals.h"
/**
 * print_sig - print signal
 * @sig: signal
 * @sig_info: siginfo_t
 * @p: pointer
 */
void print_sig(int sig, siginfo_t *sig_info, void *p)
{
	(void)p;
	(void)sig;
	printf("SIGQUIT sent by %d\n", sig_info->si_pid);
}
/**
 * trace_signal_sender - Entry point
 *
 * Return: 0 or -1
 */
int trace_signal_sender(void)
{
	struct sigaction new, old;

	new.sa_sigaction = print_sig;
	sigemptyset(&new.sa_mask);
	new.sa_flags = 0;

	return (sigaction(SIGQUIT, &new, &old));
}
