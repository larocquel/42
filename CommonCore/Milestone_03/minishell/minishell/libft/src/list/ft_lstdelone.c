/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:57:34 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 15:50:31 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
/*
void del(void *content)
{
    free(content);
}

#include <stdio.h>
#include "ft_lstnew.c"
#include "ft_strdup.c"
#include "ft_strlen.c"

int	main(void)
{
	t_list	*node1 = ft_lstnew(ft_strdup("Hello, World!"));

	printf("%s\n", (char *)node1->content);
	ft_lstdelone(node1, del);
	node1 = NULL;
}
*/
