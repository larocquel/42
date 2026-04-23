/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:53:55 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/19 20:46:38 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Sets up redirections and calls the simple executor in child.
*/
static void	child_process(t_shell *sh, t_cmd *cmd, int fd_in, int fd_out)
{
	if (fd_in != -1)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	if (fd_out != -1)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
	if (setup_redirects(cmd) != 0)
		exit_child(sh, 1);
	exec_simple_cmd(sh, cmd);
}

/*
Fork and pipe preparation for the child process.
*/
static void	exec_in_child(t_shell *sh, t_cmd *cmd, int fd_in, int pipefd[2])
{
	int	fd_out;

	setup_signals_child();
	if (cmd->next)
		close(pipefd[0]);
	fd_out = -1;
	if (cmd->next)
		fd_out = pipefd[1];
	child_process(sh, cmd, fd_in, fd_out);
}

/*
Manages FD closure in parent process to avoid leaks.
*/
static void	handle_parent_fds(int pipefd[2], int *fd_in, t_cmd *tmp)
{
	if (tmp->next)
		close(pipefd[1]);
	if (*fd_in != -1)
		close(*fd_in);
	if (tmp->next)
		*fd_in = pipefd[0];
}

/*
Waits for all children and collects the status of the last one.
*/
static void	wait_children(t_shell *sh, int last_pid)
{
	int	status;

	waitpid(last_pid, &status, 0);
	if (WIFEXITED(status))
		sh->last_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		sh->last_status = 128 + WTERMSIG(status);
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit (core dumped)", 2);
		else if (WTERMSIG(status) == SIGINT)
			write(1, "\n", 1);
	}
	while (waitpid(-1, NULL, 0) > 0)
		continue ;
}

/*
Executes the complete pipeline: Heredoc -> Fork -> Wait.
*/
void	execute_pipeline(t_shell *sh, t_cmd *cmds)
{
	int		pipefd[2];
	int		fd_in;
	pid_t	pid;
	t_cmd	*tmp;

	if (process_heredocs(sh, cmds) == 130)
		return ((void)(sh->last_status = 130));
	fd_in = -1;
	setup_signals_ignore();
	tmp = cmds;
	while (tmp)
	{
		if (tmp->next && pipe(pipefd) == -1)
			return (perror("pipe"));
		pid = fork();
		if (pid == 0)
			exec_in_child(sh, tmp, fd_in, pipefd);
		handle_parent_fds(pipefd, &fd_in, tmp);
		if (!tmp->next)
			wait_children(sh, pid);
		tmp = tmp->next;
	}
	setup_signals_interactive();
}
