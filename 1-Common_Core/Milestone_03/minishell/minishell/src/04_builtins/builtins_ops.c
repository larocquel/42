/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:57:37 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/20 22:07:24 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Builtin: cd
*/
int	ft_cd(t_shell *sh, t_cmd *cmd)
{
	char	old_pwd[4096];
	char	*path;
	int		argc;

	argc = 0;
	while (cmd->argv && cmd->argv[argc])
		argc++;
	if (argc > 2)
		return (ft_putendl_fd("minishell: cd: too many arguments", 2), 1);
	if (!getcwd(old_pwd, 4096))
		old_pwd[0] = '\0';
	if (!cmd->argv[1])
	{
		path = get_env_value(sh->env_list, "HOME");
		if (!path)
			return (ft_putendl_fd("minishell: cd: HOME not set", 2), 1);
	}
	else
		path = cmd->argv[1];
	if (chdir(path) != 0)
		return (ft_putstr_fd("minishell: cd: ", 2), perror(path), 1);
	update_wd_env(sh, old_pwd);
	return (0);
}

/*
Local helper to process each export argument
*/
static void	process_export_arg(t_shell *sh, char *arg)
{
	char	*eq_pos;

	eq_pos = ft_strchr(arg, '=');
	if (eq_pos)
	{
		*eq_pos = '\0';
		env_update(sh, arg, eq_pos + 1);
		*eq_pos = '=';
	}
	else
		env_update(sh, arg, NULL);
}

/*
Builtin: export
Modified: If no arguments, calls print_sorted_export.
*/
int	ft_export(t_shell *sh, t_cmd *cmd)
{
	int	i;

	i = 1;
	if (!cmd->argv[1])
	{
		print_sorted_export(sh);
		return (0);
	}
	while (cmd->argv[i])
	{
		if (!is_valid_key(cmd->argv[i]))
		{
			print_export_error(cmd->argv[i]);
			sh->last_status = 1;
		}
		else
			process_export_arg(sh, cmd->argv[i]);
		i++;
	}
	return (sh->last_status);
}

/*
Builtin: unset
Usage: unset VAR1 VAR2 ...
*/
int	ft_unset(t_shell *sh, t_cmd *cmd)
{
	int	i;

	i = 1;
	while (cmd->argv[i])
	{
		env_remove_node(sh, cmd->argv[i]);
		i++;
	}
	return (0);
}
