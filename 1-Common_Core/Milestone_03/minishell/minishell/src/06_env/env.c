/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:43:30 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/12 19:03:22 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Static helper: Separates KEY=VAL and adds to the list.
*/
static void	parse_and_add_env(t_shell *sh, char *env_str)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (env_str[i] && env_str[i] != '=')
		i++;
	key = ft_substr(env_str, 0, i);
	if (env_str[i] == '=')
		value = ft_strdup(env_str + i + 1);
	else
		value = NULL;
	env_add_back(&sh->env_list, env_new(key, value));
}

/*
Initializes the environment by copying the system's envp.
*/
void	init_env(t_shell *sh, char **envp)
{
	int	i;

	sh->env_list = NULL;
	i = 0;
	while (envp[i])
	{
		parse_and_add_env(sh, envp[i]);
		i++;
	}
}

/*
Returns the VALUE of a variable (string).
*/
char	*get_env_value(t_env *env, char *key)
{
	t_env	*node;

	node = env_get_node(env, key);
	if (node)
		return (node->value);
	return (NULL);
}

/*
Updates or creates a variable.
*/
void	env_update(t_shell *sh, char *key, char *value)
{
	t_env	*node;
	char	*dup_val;

	node = env_get_node(sh->env_list, key);
	if (node)
	{
		if (value)
		{
			if (node->value)
				free(node->value);
			node->value = ft_strdup(value);
		}
	}
	else
	{
		if (value)
			dup_val = ft_strdup(value);
		else
			dup_val = NULL;
		env_add_back(&sh->env_list, env_new(ft_strdup(key), dup_val));
	}
}

/*
Updates SHLVL following Bash rules.
*/
void	increment_shell_level(t_shell *sh)
{
	char	*val;
	int		lvl;
	char	*new_val;

	val = get_env_value(sh->env_list, "SHLVL");
	if (!val)
		lvl = 1;
	else
		lvl = ft_atoi(val) + 1;
	if (lvl < 0)
		lvl = 0;
	if (lvl >= 1000)
	{
		ft_putstr_fd("minishell: warning: shell level (", 2);
		ft_putnbr_fd(lvl, 2);
		ft_putendl_fd(") too high, resetting to 1", 2);
		lvl = 1;
	}
	new_val = ft_itoa(lvl);
	if (new_val)
		env_update(sh, "SHLVL", new_val);
	free(new_val);
}
