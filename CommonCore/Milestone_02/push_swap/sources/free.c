/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:29:59 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/17 13:56:54 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	ft_free(t_stack **a, t_stack **b, char **arr, int ac)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
	if (a != NULL)
		free_stack(a);
	if (b != NULL)
		free_stack(b);
}
