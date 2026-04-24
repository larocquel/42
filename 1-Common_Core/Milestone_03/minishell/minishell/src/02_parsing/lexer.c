/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:27:23 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/12 18:58:14 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Identifies and consumes operators (|, <, >, <<, >>).
*/
static t_type	read_operator(const char *s, size_t *i)
{
	if (s[*i] == '|')
		return ((*i)++, PIPE);
	if (s[*i] == '<')
	{
		if (s[*i + 1] == '<')
			return (*i += 2, R_HDC);
		return ((*i)++, R_IN);
	}
	if (s[*i] == '>')
	{
		if (s[*i + 1] == '>')
			return (*i += 2, R_APP);
		return ((*i)++, R_OUT);
	}
	return ((*i)++, WORD);
}

/*
Checks if reading the word should stop (separator outside quotes).
*/
static int	is_word_end(char c, int sq, int dq)
{
	if (!sq && !dq && ft_strchr(" \t|<>", c))
		return (1);
	return (0);
}

/*
Reads a complete word respecting quotes.
*/
static t_token	*read_word(const char *line, size_t *i)
{
	size_t	start;
	int		qs[2];
	char	*val;

	start = *i;
	qs[0] = 0;
	qs[1] = 0;
	while (line[*i])
	{
		if (line[*i] == '\'' && !qs[1])
			qs[0] = !qs[0];
		else if (line[*i] == '\"' && !qs[0])
			qs[1] = !qs[1];
		else if (is_word_end(line[*i], qs[0], qs[1]))
			break ;
		(*i)++;
	}
	if (qs[0] || qs[1])
		return (printf("Minishell: unclosed quotes\n"), NULL);
	val = ft_substr(line, start, *i - start);
	return (token_new_owned(WORD, val));
}

/*
Main Lexer loop.
*/
t_token	*tokenize_line(const char *line)
{
	size_t	i;
	t_token	*lst;
	t_token	*tok;

	lst = NULL;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
		{
			i++;
			continue ;
		}
		if (ft_strchr("|<>", line[i]))
			tok = token_new_op(read_operator(line, &i));
		else
			tok = read_word(line, &i);
		if (!tok || !token_add_back(&lst, tok))
		{
			free_tokens(lst);
			return (NULL);
		}
	}
	return (lst);
}
