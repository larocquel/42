/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:34:58 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:15:20 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strrchr() function returns a pointer to the last occurrence of
the character c in the string s.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last;

	last = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	if (last != -1)
		return ((char *)s + last);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strrchr("Apple!", 'p'));
	printf("%p\n", ft_strrchr("Apple!", 'X'));
	char *n = ft_strrchr("Apple!", '\0');
	printf("%i\n", (int)n[0]);
}
*/
