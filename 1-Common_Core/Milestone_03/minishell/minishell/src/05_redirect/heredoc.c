/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:26:05 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/19 21:24:33 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Expands variables ($VAR and $?) inside a heredoc line.
*/
static char	*expand_hd_line(t_shell *sh, char *line)
{
	char	*res;
	char	*val;
	int		i;

	res = ft_strdup("");
	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && (ft_isalnum(line[i + 1])
				|| line[i + 1] == '_' || line[i + 1] == '?'))
		{
			val = get_var_content(sh, line, &i);
			res = append_str(res, val);
			free(val);
		}
		else
			res = append_char(res, line[i++]);
	}
	free(line);
	return (res);
}

/*
Readline reading loop. Returns 130 if interrupted by signal.
*/
static int	heredoc_loop(t_shell *sh, int fd, char *delim, int expand)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			if (g_signal == 130)
				return (130);
			ft_putendl_fd("minishell: warning: heredoc delimited by EOF", 2);
			break ;
		}
		if (ft_strcmp(line, delim) == 0)
		{
			free(line);
			break ;
		}
		if (expand && ft_strchr(line, '$'))
			line = expand_hd_line(sh, line);
		ft_putendl_fd(line, fd);
		free(line);
	}
	return (0);
}

/*
Manages file opening, signal backup, execution and cleanup.
*/
static int	exec_heredoc(t_shell *sh, t_redir *r)
{
	int		fd;
	int		stdin_bkp;
	int		status;
	int		do_exp;
	char	*fname;

	fname = generate_heredoc_name();
	fd = open(fname, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (free(fname), 1);
	do_exp = check_expand_quotes(r->target);
	stdin_bkp = dup(STDIN_FILENO);
	setup_signals_heredoc();
	status = heredoc_loop(sh, fd, r->target, do_exp);
	dup2(stdin_bkp, STDIN_FILENO);
	close(stdin_bkp);
	setup_signals_interactive();
	close(fd);
	if (status == 130)
		unlink(fname);
	if (status == 130)
		return (free(fname), 130);
	return (free(r->target), r->target = fname, r->type = R_IN, 0);
}

/*
Iterates over commands and redirections processing heredocs.
*/
int	process_heredocs(t_shell *sh, t_cmd *cmds)
{
	t_cmd	*tmp;
	t_redir	*r;
	int		ret;

	tmp = cmds;
	while (tmp)
	{
		r = tmp->redirs;
		while (r)
		{
			if (r->type == R_HDC)
			{
				ret = exec_heredoc(sh, r);
				if (ret != 0)
					return (ret);
			}
			r = r->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
