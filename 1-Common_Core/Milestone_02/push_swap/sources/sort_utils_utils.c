/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:22:35 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/17 14:01:19 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*temp_a;
	t_stack	*target_node;

	if (!a || !b)
		return ;
	while (b)
	{
		temp_a = a;
		target_node = NULL;
		while (temp_a)
		{
			if ((!target_node || temp_a->n < target_node->n)
				&& temp_a->n > b->n)
				target_node = temp_a;
			temp_a = temp_a->next;
		}
		if (!target_node)
			b->target = min_n(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

t_stack	*min_n(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->n < min->n)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*return_cheapest(t_stack *stack)
{
	if (stack && !(stack)->next)
		return (stack);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while ((*b))
	{
		reset_index(a, b);
		set_target_b(*a, *b);
		cheapest = find_cheapest(b);
		while ((*b != cheapest && *a != cheapest->target)
			&& cheapest->above_median == cheapest->target->above_median)
		{
			if (cheapest->above_median == 0
				&& cheapest->target->above_median == 0)
				rr(a, b, 1);
			else if (cheapest->above_median == 1
				&& cheapest->target->above_median == 1)
				rrr(a, b, 1);
		}
		set_cheapest_to_top(b, cheapest, 2);
		set_cheapest_to_top(a, cheapest->target, 1);
		pa(a, b, 1);
	}
}

void	check_2(t_stack **stack)
{
	if ((*stack)->n > (*stack)->next->n)
		sa(stack, 1);
}
