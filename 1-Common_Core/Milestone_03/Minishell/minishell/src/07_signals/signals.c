/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:37:35 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/19 21:15:35 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal;

/*
Handler for SIGINT (Ctrl-C) in interactive mode.
*/
static void	handle_sigint(int sig)
{
	(void)sig;
	g_signal = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/*
Handler for SIGINT during Heredoc.
Closes STDIN to force readline to exit its blocking state.
*/
static void	handle_heredoc_sigint(int sig)
{
	(void)sig;
	g_signal = 130;
	write(1, "\n", 1);
	close(STDIN_FILENO);
}

/*
Configures signals for Prompt (Interactive Parent).
*/
void	setup_signals_interactive(void)
{
	struct sigaction	sa;

	signal(SIGQUIT, SIG_IGN);
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &handle_sigint;
	sigaction(SIGINT, &sa, NULL);
}

/*
Sets up signals specifically for Heredoc execution.
*/
void	setup_signals_heredoc(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &handle_heredoc_sigint);
}
