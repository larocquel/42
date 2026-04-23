/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:29:08 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 15:45:05 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*first = ft_lstnew("1");
	t_list	*second = ft_lstnew("2");
	t_list	*third = ft_lstnew("3");
	t_list	*fourth = ft_lstnew("4");
	t_list	*temp = first;

	first->next = second;
	second->next = third;
	third->next = fourth;
	while(temp)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	free(first);
	free(second);
	free(third);
	free(fourth);
}
*/
