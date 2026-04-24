/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:49:58 by lla-rocq          #+#    #+#             */
/*   Updated: 2026/01/18 16:35:15 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Adds redirection to the command's list.
*/
int	redir_add_back(t_redir **lst, t_redir *new_r)
{
	t_redir	*tmp;

	if (!new_r)
		return (0);
	if (!*lst)
	{
		*lst = new_r;
		return (1);
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_r;
	return (1);
}

/*
Creates new redirection node.
*/
t_redir	*redir_new(t_type type, const char *target)
{
	t_redir	*r;

	r = malloc(sizeof(t_redir));
	if (!r)
		return (NULL);
	r->type = type;
	r->target = ft_strdup(target);
	if (!r->target)
	{
		free(r);
		return (NULL);
	}
	r->next = NULL;
	return (r);
}

/*
Counts words until the next pipe.
*/
size_t	count_words_until_pipe(t_token *tok)
{
	size_t	count;

	count = 0;
	while (tok && tok->type != PIPE)
	{
		if (tok->type == WORD)
			count++;
		else if (tok->type != PIPE)
		{
			if (tok->next)
				tok = tok->next;
			else
				break ;
		}
		tok = tok->next;
	}
	return (count);
}

/*
Helper to print syntax error and set exit status.
*/
static int	print_syntax_error(t_shell *sh, char *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("'\n", 2);
	sh->last_status = 2;
	return (0);
}

/*
Validates general syntax (pipes at start/end, double pipes, empty redirs).
*/
int	validate_syntax(t_shell *sh, t_token *tok)
{
	if (tok && tok->type == PIPE)
		return (print_syntax_error(sh, "|"));
	while (tok)
	{
		if (tok->type == PIPE)
		{
			if (!tok->next || tok->next->type == PIPE)
				return (print_syntax_error(sh, "|"));
		}
		else if (tok->type != WORD)
		{
			if (!tok->next)
				return (print_syntax_error(sh, "newline"));
			if (tok->next->type != WORD)
				return (print_syntax_error(sh, tok->next->value));
		}
		tok = tok->next;
	}
	return (1);
}
