/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:26:07 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/12 19:01:21 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Checks for long long overflow. Returns 1 if ok, 0 if error.
Saves the result in *out.
Ignores initial spaces like bash.
*/
static int	parse_long_long(const char *str, long long *out)
{
	unsigned long long	res;
	int					sign;
	int					i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!ft_isdigit(str[i]))
		return (0);
	res = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || res > (unsigned long long)LLONG_MAX / 10
			|| (res == (unsigned long long)LLONG_MAX / 10
				&& (unsigned long long)(str[i] - '0')
			> (unsigned long long)LLONG_MAX % 10 + (sign == -1)))
			return (0);
		res = res * 10 + (str[i++] - '0');
	}
	*out = (long long)(res * sign);
	return (1);
}

/*
Builtin: exit
If number > long long or non-numeric -> error and exit(2).
If OK -> exit(num % 256).
Uses exit_child to clean up memory.
*/
int	ft_exit(t_shell *sh, t_cmd *cmd)
{
	long long	val;

	ft_putendl_fd("exit", 2);
	if (!cmd->argv[1])
		exit_child(sh, sh->last_status);
	if (!parse_long_long(cmd->argv[1], &val))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->argv[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit_child(sh, 2);
	}
	if (cmd->argv[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (1);
	}
	exit_child(sh, val % 256);
	return (0);
}

/*
Builtin: env
Prints environment variables that have a defined value.
*/
int	ft_env(t_shell *sh, t_cmd *cmd)
{
	t_env	*tmp;

	if (cmd->argv[1])
	{
		ft_putendl_fd("minishell: env: too many arguments", STDERR_FILENO);
		return (1);
	}
	tmp = sh->env_list;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(tmp->value, 1);
		}
		tmp = tmp->next;
	}
	return (0);
}

/*
Builtin: pwd
Prints current working directory.
*/
int	ft_pwd(void)
{
	char	cwd[4096];

	if (getcwd(cwd, 4096))
	{
		ft_putendl_fd(cwd, 1);
		return (0);
	}
	perror("minishell: pwd");
	return (1);
}

/*
Builtin: echo
Prints arguments. Supports -n flag (no newline).
*/
int	ft_echo(t_cmd *cmd)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (cmd->argv[1] && check_n_flag(cmd->argv[1]))
	{
		n_flag = 1;
		i++;
		while (cmd->argv[i] && check_n_flag(cmd->argv[i]))
			i++;
	}
	while (cmd->argv[i])
	{
		ft_putstr_fd(cmd->argv[i], 1);
		if (cmd->argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (n_flag == 0)
		write(1, "\n", 1);
	return (0);
}
