/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:58:59 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/17 13:57:56 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_stack_cost(t_stack **stack);

void	set_index(t_stack *stack)
{
	int	n;
	int	len;

	if (!stack)
		return ;
	n = 0;
	len = ft_stack_len(stack);
	while (stack)
	{
		stack->index = n++;
		if (stack->index < len / 2 || stack->index > len / 2)
		{
			stack->median = 0;
			if (stack->index < len / 2)
				stack->above_median = 0;
			else if (stack->index > len / 2)
				stack->above_median = 1;
		}
		else
		{
			stack->median = 1;
			stack->above_median = 0;
		}
		stack = stack->next;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*temp_b;
	t_stack	*target_node;

	if (!a || !b)
		return ;
	while (a)
	{
		temp_b = b;
		target_node = NULL;
		while (temp_b)
		{
			if ((!target_node || temp_b->n > target_node->n)
				&& temp_b->n < a->n)
				target_node = temp_b;
			temp_b = temp_b->next;
		}
		if (!target_node)
			a->target = max_n(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

t_stack	*max_n(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->n > max->n)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	reset_index(t_stack **a, t_stack **b)
{
	set_index(*a);
	if (*b && b)
		set_index(*b);
	init_stack_cost(a);
	if (*b && b)
		init_stack_cost(b);
}

static void	init_stack_cost(t_stack **stack)
{
	t_stack	*head;
	int		i;
	int		size;

	size = ft_stack_len(*stack);
	head = *stack;
	i = 0;
	while (head)
	{
		if (head->index <= (size / 2))
		{
			head->cost = head->index;
			head->above_median = 0;
		}
		else
		{
			head->above_median = 1;
			if (size % 2 == 0)
				head->cost = head->index - (head->index - (size / 2) + ++i);
			else
				head->cost = head->index - (head->index - (size / 2) + i++);
		}
		head = head->next;
	}
}
