/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:18:21 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/12 18:58:14 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Frees the token list.
Traverses the list and frees the 'value' string and the 't_token' node itself.
*/
void	free_tokens(t_token *tokens)
{
	t_token	*next;

	while (tokens)
	{
		next = tokens->next;
		if (tokens->value)
			free(tokens->value);
		free(tokens);
		tokens = next;
	}
}

/*
Frees an array of strings (char **)
Frees each string individually and then the pointer array.
*/
void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/*
Frees the redirections list (t_redir).
Traverses the list and frees the 'target' string and the 't_redir' node.
*/
void	free_redirs(t_redir *r)
{
	t_redir	*next;

	while (r)
	{
		next = r->next;
		if (r->target)
			free(r->target);
		free(r);
		r = next;
	}
}

/*
Frees the commands list (t_cmd).
Traverses the list and frees the 'argv' array,
the 'redirs' redirections list and the 't_cmd' node.
*/
void	free_cmds(t_cmd *cmds)
{
	t_cmd	*tmp;

	while (cmds)
	{
		tmp = cmds->next;
		if (cmds->argv)
			free_array(cmds->argv);
		if (cmds->redirs)
			free_redirs(cmds->redirs);
		free(cmds);
		cmds = tmp;
	}
}

/*
Frees the environment variables list (t_env).
Traverses the list and frees the 'key' and 'value' strings, and the 't_env' node.
*/
void	free_env_list(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		free(env);
		env = tmp;
	}
}
