/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:22:36 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 15:48:33 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
/*
#include <stdio.h>
#include "ft_lstnew.c"

int	main(void)
{
	t_list	*node1 = ft_lstnew("1");
	t_list	*node2 = ft_lstnew("2");
	t_list	*node3 = ft_lstnew("3");
	t_list	*list = node1;
	t_list	*temp = list;

	list->next = node1;
	node1->next = node2;
	node2->next = node3;
	while(temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	printf("Size of the list: %i\n", ft_lstsize(list));
	free(node1);
	free(node2);
	free(node3);
}
*/
