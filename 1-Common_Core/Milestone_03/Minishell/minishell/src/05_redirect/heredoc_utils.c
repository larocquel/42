/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:23:53 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/19 21:23:57 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Generates unique temporary file name.
*/
char	*generate_heredoc_name(void)
{
	static int	i = 0;
	char		*num;
	char		*name;

	num = ft_itoa(i++);
	name = ft_strjoin("/tmp/.minishell_hd_", num);
	free(num);
	return (name);
}

/*
Checks if delimiter has quotes. If so, removes them and returns 0 (no expand).
Else returns 1 (expand).
*/
int	check_expand_quotes(char *delimiter)
{
	if (ft_strchr(delimiter, '\'') || ft_strchr(delimiter, '\"'))
	{
		remove_quotes_final(delimiter);
		return (0);
	}
	return (1);
}

/*
Helper for expand_hd_line: extracts variable key and gets value.
Updates index 'i' passed by reference.
*/
char	*get_var_content(t_shell *sh, char *line, int *i)
{
	int		start;
	char	*key;
	char	*val;

	(*i)++;
	if (line[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(sh->last_status));
	}
	start = *i;
	while (line[*i] && (ft_isalnum(line[*i]) || line[*i] == '_'))
		(*i)++;
	key = ft_substr(line, start, *i - start);
	val = get_env_value(sh->env_list, key);
	if (val)
		val = ft_strdup(val);
	else
		val = ft_strdup("");
	free(key);
	return (val);
}
