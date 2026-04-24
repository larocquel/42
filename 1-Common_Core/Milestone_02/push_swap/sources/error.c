/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:24:30 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/22 22:45:04 by leoaguia         ###   ########.fr       */
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

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	only_numbers(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!is_valid_number(arr[i]))
			return (0);
		i++;
	}
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
