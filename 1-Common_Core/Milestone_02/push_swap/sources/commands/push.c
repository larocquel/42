/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:58:25 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/17 14:04:57 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack **origin, t_stack **dest)
{
	t_stack	*temp;

	if (!(*origin))
		return ;
	temp = *origin;
	*origin = (*origin)->next;
	temp->next = *dest;
	*dest = temp;
}

void	pa(t_stack **a, t_stack **b, int n)
{
	push(b, a);
	if (n != 0)
		ft_printf("pa\n");
	return ;
}

void	pb(t_stack **a, t_stack **b, int n)
{
	push (a, b);
	if (n != 0)
		ft_printf("pb\n");
	return ;
}
