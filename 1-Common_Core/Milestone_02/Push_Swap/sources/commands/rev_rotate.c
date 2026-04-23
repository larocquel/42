/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:09:51 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/17 14:05:30 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a, int n)
{
	rev_rotate(a);
	if (n != 0)
		ft_printf("rra\n");
	return ;
}

void	rrb(t_stack **b, int n)
{
	rev_rotate(b);
	if (n != 0)
		ft_printf("rrb\n");
	return ;
}

void	rrr(t_stack **a, t_stack **b, int n)
{
	rev_rotate(a);
	rev_rotate(b);
	if (n != 0)
		ft_printf("rrr\n");
	return ;
}
