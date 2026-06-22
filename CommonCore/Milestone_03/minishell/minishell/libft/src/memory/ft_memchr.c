/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:05:26 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:29:50 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
memchr: Scans n bytes of the memory area s for the first instance of c.

s: Area of the memory.

c: Int value we want to find in the memory.

n: Number of bytes to scan.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	target;

	ptr = (unsigned char *)s;
	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == target)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include "ft_strlen.c"

int main(void)
{
    char str[] = "Hello, world!";
    char ch = 'w';

    char *result = ft_memchr(str, ch, ft_strlen(str));

    if (result != NULL)
        printf("The character '%c' is in position: %ld\n", ch, result - str);
    else
        printf("The character '%c' was not found.\n", ch);
}
*/
