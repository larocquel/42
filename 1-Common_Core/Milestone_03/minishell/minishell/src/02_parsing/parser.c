/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:59:10 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/18 16:23:21 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Processes redirections.
Advances the 'tok' pointer past the target (redir + target).
*/
static int	handle_redir(t_cmd *cmd, t_token **tok)
{
	t_redir	*r;

	if (!(*tok)->next || (*tok)->next->type != WORD)
		return (0);
	r = redir_new((*tok)->type, (*tok)->next->value);
	if (!r)
		return (0);
	if (!redir_add_back(&cmd->redirs, r))
	{
		free_redirs(r);
		return (0);
	}
	*tok = (*tok)->next->next;
	return (1);
}

/*
Allocates the command structure and the arguments array.
*/
static t_cmd	*init_cmd(t_token *start)
{
	t_cmd	*cmd;
	size_t	len;

	len = count_words_until_pipe(start);
	if (len == 0 && start->type == PIPE)
		return (NULL);
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->redirs = NULL;
	cmd->next = NULL;
	cmd->argv = malloc(sizeof(char *) * (len + 1));
	if (!cmd->argv)
	{
		free(cmd);
		return (NULL);
	}
	return (cmd);
}

/*
Processes a single token (either WORD or REDIR).
Returns 0 on error, 1 on success.
*/
static int	fill_cmd_args(t_cmd *cmd, t_token **tok, int *i)
{
	if ((*tok)->type == WORD)
	{
		cmd->argv[(*i)++] = ft_strdup((*tok)->value);
		if (!cmd->argv[*i - 1])
			return (0);
		*tok = (*tok)->next;
	}
	else if (!handle_redir(cmd, tok))
		return (0);
	return (1);
}

/*
Creates a command consuming tokens until finding a PIPE.
*/
static t_cmd	*create_cmd(t_token **cur)
{
	t_cmd	*cmd;
	int		i;
	t_token	*tok;

	cmd = init_cmd(*cur);
	if (!cmd)
		return (NULL);
	i = 0;
	tok = *cur;
	while (tok && tok->type != PIPE)
	{
		if (!fill_cmd_args(cmd, &tok, &i))
		{
			free_cmds(cmd);
			return (NULL);
		}
	}
	cmd->argv[i] = NULL;
	*cur = tok;
	return (cmd);
}

/*
Main parser function.
Generates the linked list of commands.
*/
t_cmd	*parse_pipeline(t_shell *sh, t_token *tokens)
{
	t_cmd	*head;
	t_cmd	*curr;
	t_cmd	*new_node;
	t_token	*tok;

	if (!tokens || !validate_syntax(sh, tokens))
		return (NULL);
	head = NULL;
	curr = NULL;
	tok = tokens;
	while (tok)
	{
		new_node = create_cmd(&tok);
		if (!new_node)
			return (free_cmds(head), NULL);
		if (!head)
			head = new_node;
		else
			curr->next = new_node;
		curr = new_node;
		if (tok && tok->type == PIPE)
			tok = tok->next;
	}
	return (head);
}
