/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:46:13 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:15:11 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*little))
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (big[i] == little[j] && little[j] && i < len)
		{
			j++;
			i++;
		}
		if (little[j] == '\0')
			return ((char *)big + i - j);
		i -= j;
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main(void)
{
	const char *big = "Hello, welcome to 42!";
	const char *little = "welcome";
	char *result = ft_strnstr(big, little, 14);

    if (result)
		printf("Found: %s\n", result);
	else
		printf("Not found within the specified range.\n");
}
*/
