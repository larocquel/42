/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:01:50 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 15:58:59 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void print_node(void *content)
{
    printf("%s\n", (char *)content);
}

void del(void *content)
{
    free(content);
}

#include <stdio.h>
#include "ft_lstnew.c"
#include "ft_strdup.c"
#include "ft_strlen.c"
#include "ft_lstclear.c"
#include "ft_lstdelone.c"

int	main(void)
{
	t_list	*node1 = ft_lstnew(ft_strdup("Hello"));
	t_list	*node2 = ft_lstnew(ft_strdup("World!"));

	node1->next = node2;

	ft_lstiter(node1, print_node);
	ft_lstclear(&node1, del);
}
*/
