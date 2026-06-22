/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:20:34 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 15:50:49 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	void	*content;

	newlst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		newnode = ft_lstnew(content);
		if (!newnode)
		{
			del(content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}
/*
#include <stdio.h>
#include "ft_lstnew.c"
#include "ft_lstadd_back.c"
#include "ft_lstlast.c"
#include "ft_lstclear.c"
#include "ft_lstdelone.c"

void del(void *content)
{
	free(content);
}

void *ft_plusone(void *content)
{
	int *new_value = malloc(sizeof(int));
	if (!new_value)
		return (NULL);
	*new_value = *(int *)content + 1;
	return (new_value);
}

int	main(void)
{
	int a = 1, b = 2, c = 3;
	t_list	*node1 = ft_lstnew(&a);
	t_list	*node2 = ft_lstnew(&b);
	t_list	*node3 = ft_lstnew(&c);
	t_list	*list = node1;
	node1->next = node2;
	node2->next = node3;
	t_list	*new_list = ft_lstmap(list, ft_plusone, del);
	t_list *temp = new_list;
	while (temp)
	{
		printf("%d\n", *(int *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&new_list, del);
	free(node1);
	free(node2);
	free(node3);
}
*/
