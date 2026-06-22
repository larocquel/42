#include <stdbool.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

void	alarm_handler(int sig)
{
	(void)sig;
}

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	struct sigaction	sa;
	pid_t				pid;
	int					status;

	// 1. Escudo - Pai x SIGALRM
	sa.sa_handler = alarm_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGALRM, &sa, NULL) == -1)
		return (-1);

	// 2. Clone
	pid = fork();

	if (pid == -1)
		return (-1);

	// 3. Filho - Executor
	if (pid == 0)
	{
		f();
		exit(0);
	}

	// 4. Pai - Bomba, Check1, Defusa, Check2

	// 5. Bomba
	alarm(timeout);

	// 6. Check 1 - timeout
	if (waitpid(pid, &status, 0) == -1)
	{
		if (errno == EINTR)
		{
			// Mata filho
			kill(pid, SIGKILL);
			// Mata zumbi
			waitpid(pid, &status, 0);
			// Printa
			if (verbose)
				printf("Bad function: timed out after %u seconds\n", timeout);
			return (0);
		}
		return (-1);
	}

	// 7. Defuse
	alarm(0);

	// 8. Check 2 - exited or signaled
	if (WIFEXITED(status))
	{
		int	exit_code = WEXITSTATUS(status);

		if (exit_code == 0)
		{
			if (verbose)
				printf("Nice function!\n");
			return(1);
		}
		else
		{
			if (verbose)
				printf("Bad function: exited with code %d\n", exit_code);
			return(0);
		}
	}
	else if (WIFSIGNALED(status))
	{
		if (verbose)
			printf("Bad function: %s\n", strsignal(WTERMSIG(status)));
		return(0);
	}
	return (-1);
}