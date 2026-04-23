/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:33:06 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 15:59:45 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
#include <stdio.h>
#include "ft_lstnew.c"
#include "ft_lstlast.c"

int	main(void)
{
	t_list	*node1 = ft_lstnew("1");
	t_list	*node2 = ft_lstnew("2");
	t_list	*node3 = ft_lstnew("3");

	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node2, node3);

	t_list	*temp = node1;

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
