/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:17:33 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:51:44 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
size_t strlcpy(char *dst, const char *src, size_t size);

dst: Pointer to the destination buffer where the string will be copied

src: Pointer to the source string to be copied to dest

size: Size of the dst buffer or the max number of bytes that dst can hold
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	copy_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		if (src_len >= size)
			copy_len = size - 1;
		else
			copy_len = src_len;
		i = 0;
		while (i < copy_len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[copy_len] = '\0';
	}
	return (src_len);
}
/*
#include <stdio.h>
#include "ft_strlen.c"

int main(void)
{
    char src[] = "Example of a long string";
    char dest[25];
    size_t n;

    n = ft_strlcpy(dest, src, sizeof(dest));

    printf("Copied string: %s\n", dest);
    printf("Required size: %zu\n", n);

    if (n >= sizeof(dest))
        printf("The string was interrupted.\n");
	else
        printf("The string was fully copied.\n");
}
*/
