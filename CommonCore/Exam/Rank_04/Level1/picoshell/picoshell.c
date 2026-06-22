#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	pid_t	pid;
	int		fd[2];
	int		prev_fd = -1;
	int		i = 0;

	// 1. Loop
	while (cmds[i])
	{
		// 2. Tubos - Ha prox comando?
		if (cmds[i + 1])
		{
			if (pipe(fd) == -1)
			{
				if (prev_fd != -1)
					close(prev_fd);
				return (1);
			}
		}

		// 3. Clonagem
		pid = fork();

		if (pid == -1)
		{
			if (prev_fd != -1)
				close(prev_fd);
			if (cmds[i + 1])
			{
				close(fd[0]);
				close(fd[1]);
			}
			return (1);
		}

		// 4. Filho - Redirecionador
		if (pid == 0)
		{
			// Tubo anterior - Entrada - STDIN
			if (prev_fd != -1)
			{
				if (dup2(prev_fd, STDIN_FILENO) == -1)
				{
					close(prev_fd);
					if (cmds[i + 1])
					{
						close(fd[0]);
						close(fd[1]);
					}
					exit(1);
				}
				close(prev_fd);
			}
			// Tubo posterior - Saida - STDOUT
			if (cmds[i + 1])
			{
				if (dup2(fd[1], STDOUT_FILENO) == -1)
				{
					close(fd[0]);
					close(fd[1]);
					exit(1);
				}
				close(fd[0]);
				close(fd[1]);
			}
			// Executar
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}

		// 5. Pai - Encanador
		// Anterior
		if (prev_fd != -1)
			close(prev_fd);
		// Posterior
		if (cmds[i + 1])
		{
			close(fd[1]);
			prev_fd = fd[0];
		}
		i++;
	}

	// 6. Espera Final
	while (wait(NULL) != -1)
		;

	// 7. Sucesso
	return (0);
}