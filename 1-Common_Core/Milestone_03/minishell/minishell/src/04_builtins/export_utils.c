/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:52:06 by leoaguia          #+#    #+#             */
/*   Updated: 2026/01/12 19:02:21 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Counts how many nodes exist in the environment list.
*/
static int	env_list_size(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

/*
Sorts the array of pointers using Bubble Sort.
Compares the keys alphabetically.
*/
static void	sort_env_array(t_env **arr, int size)
{
	int		i;
	int		j;
	t_env	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(arr[j]->key, arr[j + 1]->key) > 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/*
Helper function to print a single export line.
*/
static void	print_one_export(t_env *node)
{
	printf("declare -x %s", node->key);
	if (node->value)
		printf("=\"%s\"", node->value);
	printf("\n");
}

/*
Main function called by ft_export when without arguments.
1. Creates pointer array.
2. Sorts.
3. Prints in format declare -x VAR="VAL".
4. Frees the array (but not the nodes).
*/
void	print_sorted_export(t_shell *sh)
{
	t_env	**arr;
	t_env	*tmp;
	int		count;
	int		i;

	count = env_list_size(sh->env_list);
	arr = malloc(sizeof(t_env *) * count);
	if (!arr)
		return ;
	tmp = sh->env_list;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp;
		tmp = tmp->next;
	}
	sort_env_array(arr, count);
	i = -1;
	while (++i < count)
		print_one_export(arr[i]);
	free(arr);
}
