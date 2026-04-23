/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:43:47 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/17 14:04:29 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_stacks_utils(t_stack **a, t_stack **b, size_t len);

int	ft_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->n > stack->next->n)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort_three(t_stack **s)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*s)->n;
	n2 = (*s)->next->n;
	n3 = (*s)->next->next->n;
	if (n1 > n2 && n2 > n3)
	{
		sa(s, 1);
		rra(s, 1);
	}
	else if (n1 > n3 && n3 > n2)
		ra(s, 1);
	else if (n2 > n1 && n1 > n3)
		rra(s, 1);
	else if (n1 > n2 && n1 < n3)
		sa(s, 1);
	else if (n2 > n3)
	{
		sa(s, 1);
		ra(s, 1);
	}
}

void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	size_t	len;
	int		count;

	if (!a || !*a)
		return ;
	count = 2;
	len = ft_stack_len(*a);
	while (len > 3 && count > 0)
	{
		pb(a, b, 1);
		len--;
		count--;
	}
	sort_stacks_utils(a, b, len);
	push_b_to_a(a, b);
	reset_index(a, b);
	lower_on_top(a);
}

static void	sort_stacks_utils(t_stack **a, t_stack **b, size_t len)
{
	t_stack	*cheapest;

	while ((*a)->next->next->next)
	{
		reset_index(a, b);
		set_target_a(*a, *b);
		cheapest = find_cheapest(a);
		while ((*a != cheapest && *b != cheapest->target)
			&& cheapest->above_median == cheapest->target->above_median)
		{
			if (cheapest->above_median == 0)
				rr(a, b, 1);
			else if (cheapest->above_median == 1)
				rrr(a, b, 1);
		}
		set_cheapest_to_top(a, cheapest, 1);
		set_cheapest_to_top(b, cheapest->target, 2);
		pb(a, b, 1);
		len--;
	}
	ft_sort_three(a);
	reset_index(a, b);
}

void	set_cheapest_to_top(t_stack **stack, t_stack *node, int checker)
{
	while (*stack != node)
	{
		if (checker == 1)
		{
			if (node->above_median == 0)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (checker == 2)
		{
			if (node->above_median == 0)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}
