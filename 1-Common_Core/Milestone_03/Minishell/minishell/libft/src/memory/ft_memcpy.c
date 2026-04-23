/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:04:03 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:31:49 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
memcpy: Used to copy blocks of memory from one region to another.

dest: Pointer to the destination where the copied data will be stored.

src: Pointer to the source, where the data we want to copy is located.

n: Number of bytes we want to copy from the memory of src to dest.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
    int size = 5;
    int src[] = {1, 2, 3, 4, 5};
    int dest[size];
    int i = 0;

    ft_memcpy(dest, src, size * sizeof(int));

    while(i < size)
        printf("%d ", dest[i++]);
}
*/
