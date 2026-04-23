/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:25:17 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/12 19:02:01 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Helper for ft_exit: Checks if string is numeric
*/
int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
Checks -n flag.
Returns 1 if valid -n (ex: -n, -nnnn), 0 otherwise.
*/
int	check_n_flag(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-' || arg[1] != 'n')
		return (0);
	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

/*
Helper for CD:
Updates OLDPWD with the old path (old) and PWD with the current one.
*/
void	update_wd_env(t_shell *sh, char *old)
{
	char	cwd[4096];

	if (old && *old)
		env_update(sh, "OLDPWD", old);
	if (getcwd(cwd, 4096))
		env_update(sh, "PWD", cwd);
}

/*
Helper for export: Prints invalid identifier error
*/
void	print_export_error(char *arg)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd("': not a valid identifier", 2);
}

/*
Checks if a string is a valid identifier for environment variables.
Rules:
1. Must start with letter or _.
2. Rest must be alphanumeric or _.
3. Stop at '='.
*/
int	is_valid_key(char *str)
{
	int	i;

	i = 0;
	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i++;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
