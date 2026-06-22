/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:26:06 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/12 18:59:31 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Processes the variable $VAR or $?.
Returns the new index i.
*/
static int	handle_dollar(char *str, int i, char **res, t_shell *sh)
{
	int		start;
	char	*key;
	char	*val;

	i++;
	if (str[i] == '?')
	{
		val = ft_itoa(sh->last_status);
		*res = append_str(*res, val);
		free(val);
		return (i + 1);
	}
	if (ft_isdigit(str[i]) || (!ft_isalpha(str[i]) && str[i] != '_'))
	{
		if (!ft_isdigit(str[i]))
			*res = append_char(*res, '$');
		return (i + (ft_isdigit(str[i]) != 0));
	}
	start = i;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	key = ft_substr(str, start, i - start);
	*res = append_str(*res, get_env_value(sh->env_list, key));
	free(key);
	return (i);
}

/*
Controls the quotes state during expansion.
*/
static void	update_quotes(char c, int *sq, int *dq)
{
	if (c == '\'' && !(*dq))
		*sq = !(*sq);
	else if (c == '\"' && !(*sq))
		*dq = !(*dq);
}

/*
Expands WORD type tokens.
Handles quotes and environment variables.
*/
void	expand_token(t_token *tok, t_shell *sh)
{
	char	*new;
	int		i;
	int		qs[2];

	new = ft_strdup("");
	i = 0;
	qs[0] = 0;
	qs[1] = 0;
	while (tok->value[i])
	{
		update_quotes(tok->value[i], &qs[0], &qs[1]);
		if (tok->value[i] == '\'' && !qs[1])
			new = append_char(new, tok->value[i++]);
		else if (tok->value[i] == '\"' && !qs[0])
			new = append_char(new, tok->value[i++]);
		else if (tok->value[i] == '$' && !qs[0])
			i = handle_dollar(tok->value, i, &new, sh);
		else
			new = append_char(new, tok->value[i++]);
	}
	free(tok->value);
	tok->value = new;
	remove_quotes_final(tok->value);
}

/*
Iterates over the token list and expands WORDS.
*/
void	expand_all_tokens(t_shell *sh, t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == WORD)
			expand_token(tmp, sh);
		tmp = tmp->next;
	}
}
