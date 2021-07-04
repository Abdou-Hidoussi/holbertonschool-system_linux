#include "signals.h"
/**
 * sigset_init - function that initializes a sigset
 * @set: pointer to the signal set to initialize
 * @signals: array of int, each one being a signal number
 * Return: 0 on success, or -1 on error
 */
int sigset_init(sigset_t *set, int *signals)
{
	int i;

	if (sigemptyset(set))
		return (0);
	for (i = 0; signals[i]; i++)
	{
		if (sigaddset(set, signals[i]))
			return (-1);
	}
	return (0);
}
/**
 * signals_block - lock a given set of signals
 * @signals: array of int, each one being a signal number
 * Return: 0 on success, or -1 on error
 */
int signals_block(int *signals)
{
	sigset_t set;

	if (sigset_init(&set, signals))
		return (-1);
	return (sigprocmask(SIG_BLOCK, &set, NULL));
}
