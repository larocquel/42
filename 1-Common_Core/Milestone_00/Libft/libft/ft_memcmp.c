/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:49:43 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:28:57 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
memcmp: Compares  the first n bytes of the memory areas s1 and s2.

s1: Pointer to the first memory block.

s2: Pointer to the second memory block.

n: Number of bytes to compare between the two blocks.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*m1;
	unsigned char	*m2;

	m1 = (unsigned char *)s1;
	m2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (m1[i] != m2[i])
			return (m1[i] - m2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include "ft_atoi.c"

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("s1: %s\ns2: %s\nn: %s\n", av[1], av[2], av[3]);
		printf("Result: %i\n", ft_memcmp(av[1], av[2], ft_atoi(av[3])));
	}
	else
		printf("Usage: %s s1 s2 n\n", av[0]);
}
*/
