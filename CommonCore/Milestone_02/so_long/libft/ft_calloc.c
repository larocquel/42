/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:02:19 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 15:51:35 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
ft_calloc() allocates memory for an array and initialize that memory to zero.

nmemb: number os elements

size: number of bytes
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new;

	new = malloc(nmemb * size);
	if (!new)
		return (NULL);
	ft_bzero(new, nmemb * size);
	return ((void *)new);
}

/*
#include <stdio.h>
#include "ft_bzero.c"

int	main(void)
{
	size_t	nm = 4;
	size_t	size = sizeof(int);
	int	*new = ft_calloc(nm, size);

	if (new != NULL)
		for(int i = 0; i < nm; i++)
			printf("%i ", new[i]);
	else
		printf("Error");
	free(new);
}
*/
