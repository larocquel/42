/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:54:53 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:44:32 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Find X, please!";
	int	c1 = 'X';
	int	c2 = 'Y';
	int	c3 = '\0';

	// Test 1: 'X' is inside of 'Find X, please'
	printf("Test 1:\n");
	printf("s = %s\nc = %c\n", str, c1);
	printf("Result: %s\n", ft_strchr(str, c1));

	// Test 2: 'Y' is inside of 'Find X, please'
	printf("\nTest 2:\n");
	printf("s = %s\nc = %c\n", str, c2);
	printf("Result: %s\n", ft_strchr(str, c2));

	// Test 3: If c is '\0' the return is the terminator.
	printf("\nTest 3:\n");
	printf("s = %s\nc = %i\n", str, c3);
	char *s2 = ft_strchr(str, c3);
	printf("Null char test: %i", s2[0]);
}
*/
