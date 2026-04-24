/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:21:51 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 15:25:13 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The bzero function is used to set a block of memory to zero.

s: A pointer to the starting address of the memory block.

n: The number of bytes to set to zero.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char buffer[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	printf("Before: %s\n", buffer);
	ft_bzero(buffer, sizeof(buffer));
	printf("After : ");
	int i = 0;
	while(i < 26)
		printf("%d", buffer[i++]);
}
*/
