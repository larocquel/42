/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:49:19 by lla-rocq          #+#    #+#             */
/*   Updated: 2026/01/12 18:59:31 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Creates token with a copy of the value string.
*/
t_token	*token_new(t_type type, const char *start, size_t len)
{
	t_token	*tok;
	size_t	i;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->value = malloc(len + 1);
	if (!tok->value)
	{
		free(tok);
		return (NULL);
	}
	i = -1;
	while (++i < len)
		tok->value[i] = start[i];
	tok->value[len] = '\0';
	tok->type = type;
	tok->next = NULL;
	return (tok);
}

/*
Creates token consuming the value string (pointer handover).
*/
t_token	*token_new_owned(t_type type, char *value)
{
	t_token	*tok;

	tok = malloc(sizeof(t_token));
	if (!tok)
	{
		free(value);
		return (NULL);
	}
	tok->type = type;
	tok->value = value;
	tok->next = NULL;
	return (tok);
}

/*
Factory for fixed operator tokens.
*/
t_token	*token_new_op(t_type type)
{
	if (type == PIPE)
		return (token_new(type, "|", 1));
	if (type == R_IN)
		return (token_new(type, "<", 1));
	if (type == R_OUT)
		return (token_new(type, ">", 1));
	if (type == R_APP)
		return (token_new(type, ">>", 2));
	if (type == R_HDC)
		return (token_new(type, "<<", 2));
	return (NULL);
}

/*
Adds token to the end of the linked list.
*/
int	token_add_back(t_token **lst, t_token *new_tok)
{
	t_token	*tmp;

	if (!new_tok)
		return (0);
	if (!*lst)
	{
		*lst = new_tok;
		return (1);
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_tok;
	return (1);
}
