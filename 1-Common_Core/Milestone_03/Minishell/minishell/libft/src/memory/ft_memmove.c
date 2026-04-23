/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:15:39 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:33:36 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memmove: Moves blocks of memory from one location to another.

dest: Pointer to the destination memory block where the data will be moved.

src: Pointer to the source memory block from which the data will be copied.

n: Number of bytes to be moved.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
    char str[] = "Hello, world!";

    printf("Before: %s\n", str);
    ft_memmove(str, str + 7, 6);
    printf("After: %s\n", str);
}
*/
