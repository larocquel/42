/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:05:14 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/17 14:06:07 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	sa(t_stack **a, int n)
{
	swap(a);
	if (n != 0)
		ft_printf("sa\n");
	return ;
}

void	sb(t_stack **b, int n)
{
	swap(b);
	if (n != 0)
		ft_printf("sb\n");
	return ;
}

void	ss(t_stack **a, t_stack **b, int n)
{
	swap(a);
	swap(b);
	if (n != 0)
		ft_printf("ss\n");
	return ;
}
