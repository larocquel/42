/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:56:21 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/17 14:05:18 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = ft_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	ra(t_stack **a, int n)
{
	rotate(a);
	if (n != 0)
		ft_printf("ra\n");
	return ;
}

void	rb(t_stack **b, int n)
{
	rotate(b);
	if (n != 0)
		ft_printf("rb\n");
	return ;
}

void	rr(t_stack **a, t_stack **b, int n)
{
	rotate(a);
	rotate(b);
	if (n != 0)
		ft_printf("rr\n");
	return ;
}
