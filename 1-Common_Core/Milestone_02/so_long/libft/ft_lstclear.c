/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:20:35 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 15:50:22 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
/*
void del(void *content)
{
    free(content);
}

#include <stdio.h>
#include "ft_lstdelone.c"
#include "ft_lstnew.c"
#include "ft_strdup.c"
#include "ft_strlen.c"

int	main(void)
{
	t_list	*node1 = ft_lstnew(ft_strdup("1"));
	t_list	*node2 = ft_lstnew(ft_strdup("2"));
	t_list	*node3 = ft_lstnew(ft_strdup("3"));
	t_list	*node4 = ft_lstnew(ft_strdup("4"));
	t_list	*temp = node1;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	while(temp)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&node1, del);
	if (node1 == NULL)
		printf("\nSuccess on free()\n");
}
*/
