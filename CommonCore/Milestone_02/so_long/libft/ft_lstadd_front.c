/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:00:21 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:00:05 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
#include "ft_lstnew.c"

int	main(void)
{
	t_list	*node1 = ft_lstnew("1");
	t_list	*node2 = ft_lstnew("2");
	t_list	*node3 = ft_lstnew("3");
	t_list	*new = ft_lstnew("42");

	ft_lstadd_front(&node3, node2);
	ft_lstadd_front(&node2, node1);
	ft_lstadd_front(&node1, new);

	t_list *temp = new;

	while(temp)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	node1->next = NULL;
	node2->next = NULL;
	node3->next = NULL;
	free(node1);
	free(node2);
	free(node3);
}
*/
