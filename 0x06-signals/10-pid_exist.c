#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
/**
 * pid_exist - tests if a process exists, given its PID
 * @pid: process id
 * Return: 1 if the process with the PID pid exists, or 0 otherwise
 */
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) + 1);
}
