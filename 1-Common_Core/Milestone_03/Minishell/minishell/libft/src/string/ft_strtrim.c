/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:53:46 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:15:34 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s1: The string to be trimmed.

set: The reference set of characters to trim.
*/
#include "libft.h"

static int	ft_strlet(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		len;
	int		i;

	start = 0;
	while (ft_strlet(s1[start], set) && s1[start])
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strlet(s1[end], set) && end >= start)
		end--;
	len = end - start + 1;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
#include "ft_strlen.c"

int	main(void)
{
	char	s1[] = "ABColamundoCBA";
	char	set[] = "ABC";

	printf("%s\n", ft_strtrim(s1, set));
}
*/
