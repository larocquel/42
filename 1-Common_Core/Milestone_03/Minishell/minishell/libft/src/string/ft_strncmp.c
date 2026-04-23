/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:24:57 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:15:00 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
    const char *str1 = "Hello";
    const char *str2 = "HelLo";
    const char *str3 = "Hell";

    printf("'%s' and '%s' n = 5: %d\n", str1, str1, ft_strncmp(str1, str1, 5));
    printf("'%s' and '%s' n = 5: %d\n", str1, str2, ft_strncmp(str1, str2, 5));
	printf("'%s' and '%s'  n = 5: %d\n", str1, str3, ft_strncmp(str1, str3, 5));
    printf("'%s' and '%s'  n = 4: %d\n", str1, str3, ft_strncmp(str1, str3, 4));
}
*/
