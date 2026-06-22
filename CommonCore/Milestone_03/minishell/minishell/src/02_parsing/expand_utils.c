/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:38:26 by lla-rocq          #+#    #+#             */
/*   Updated: 2026/01/12 18:59:59 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Adds a char to the end of the string.
Returns new string and frees the old one.
*/
char	*append_char(char *str, char c)
{
	char	*new;
	size_t	len;

	if (!str)
		str = ft_strdup("");
	len = ft_strlen(str);
	new = malloc(len + 2);
	if (!new)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(new, str, len + 1);
	new[len] = c;
	new[len + 1] = '\0';
	free(str);
	return (new);
}

/*
Adds a string to the end of another.
Returns new string and frees the base.
*/
char	*append_str(char *base, char *val)
{
	char	*new_str;

	if (!base)
		base = ft_strdup("");
	if (!val)
		return (base);
	new_str = ft_strjoin(base, val);
	free(base);
	return (new_str);
}

/*
Helper: Removes quotes from the final string.
Copies chars ignoring outer quotes.
*/
void	remove_quotes_final(char *str)
{
	int	i;
	int	j;
	int	qs[2];

	i = 0;
	j = 0;
	qs[0] = 0;
	qs[1] = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !qs[1])
			qs[0] = !qs[0];
		else if (str[i] == '\"' && !qs[0])
			qs[1] = !qs[1];
		else
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}
