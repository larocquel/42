#include <stdbool.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void	alarm_handler(int sig)
{
	(void)sig;
}

int	sandbox(void (*f)(void), unsigned int timeout, int verbose)
{
	struct sigaction	sa;
	pid_t				pid;
	int					status;

	// Armar escudo do Pai (contra SIGALRM)
	sa.sa_handler = alarm_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGALRM, &sa, NULL) == -1)
		return (-1);

	// Fork
	pid = fork();

	// Error check
	if (pid == -1)
		return (-1);

	// Processo Filho - Executor
	if (pid == 0)
	{
		f();
		exit(0);
	}

	// Processo Pai - Bomba, Check 1, Defuse, Check 2

	// Bomba
	alarm(timeout);

	// Check 1 - timeout
	if (waitpid(pid, &status, 0) == -1)
	{
		if (errno == EINTR)
		{
			// Mata o filho
			kill(pid, SIGKILL);
			// Recolhe o corpo do filho
			waitpid(pid, &status, 0);
			if (verbose)
				printf("Bad function: timed out after %u seconds\n", timeout);
			return (0);
		}
		return (-1);
	}

	// Defuse
	alarm(0);

	// Check 2 - nice, exitcode or signal
	if (WIFEXITED(status))
	{
		int	exit_code = WEXITSTATUS(status);

		if (exit_code == 0)
		{
			if (verbose)
				printf("Nice function!\n");
			return (1);
		}
		else
		{
			if (verbose)
				printf("Bad function: exited with code %d\n", exit_code);
			return (0);
		}

	}
	else if (WIFSIGNALED(status))
	{
		if (verbose)
			printf("Bad function: %s\n", strsignal(WTERMSIG(status)));
		return (0);
	}
	return (-1);
}

void	nice_function(void)
{
	return ;
}

void	bf_segfault(void)
{
	int	*null_pointer = NULL;
	*null_pointer = 42;
}

void	bf_abort(void)
{
	abort(); // Crash the function by sending a SIGABRT signal
}

void	bf_exitcode(void)
{
	exit(42);
}

void	bf_timeout(void)
{
	while (1)
		;
}

void very_bad_function(void)
{
	signal(SIGALRM, SIG_IGN); // Ignora o alarme!
	while(1)
	{}
}

int	main(void)
{
	printf("--- VERBOSE = TRUE ---\n");
	sandbox(nice_function, 1, true);
	sandbox(bf_segfault, 1, true);
	sandbox(bf_abort, 1, true);
	sandbox(bf_exitcode, 1, true);
	sandbox(bf_timeout, 2, true);
	sandbox(very_bad_function, 10, true);

	printf("--- VERBOSE = FALSE ---\n");
	sandbox(nice_function, 1, false);
	sandbox(bf_segfault, 1, false);
	sandbox(bf_abort, 1, false);
	sandbox(bf_exitcode, 1, false);
	sandbox(bf_timeout, 2, false);
}