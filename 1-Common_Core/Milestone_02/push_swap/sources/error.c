/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:24:30 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/17 14:02:56 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_error(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
	a = NULL;
	return (ft_putstr_fd("Error\n", 2), -1);
}

static int	only_zero(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static int	valid_size(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '-' && ft_strlen(arr[i]) > 20
				&& only_zero(arr[i]) == 0)
				return (0);
			else if (j == 0 && ft_strlen(arr[i]) > 19
				&& only_zero(arr[i]) == 0)
				return (0);
			else
				break ;
		}
		i++;
	}
	return (1);
}

int	only_numbers(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '-' || arr[i][j] == '+')
			{
				if (!ft_isdigit(arr[i][j + 1]))
					return (0);
				else if (j > 1 && ft_isdigit(arr[i][j - 1]))
					return (0);
			}
			else if (!ft_isdigit(arr[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (valid_size(arr) == 0)
		return (0);
	return (1);
}

int	doubles(t_stack *stack, int n)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (n == stack->n)
			return (0);
		stack = stack->next;
	}
	return (1);
}
