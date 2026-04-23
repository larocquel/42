/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:13:00 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:34:57 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr++ = c;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = "Run Forest!";
	char s2[] = "Run Forest!";
	int n = 'A';

	printf("Mine\n");
	printf("Before: %s\n", s1);
	ft_memset(s1, n, 4);
	printf("After : %s\n\n", s1);

	printf("Original\n");
	printf("Before: %s\n", s2);
	memset(s2, n, 4);
	printf("After : %s\n", s2);
}
*/
