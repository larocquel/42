/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:53:50 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 17:08:04 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s: The string from which to create the substring.

start: The start index of the substring in the string ’s’.

len: The maximum length of the substring.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
/*
#include "ft_putstr_fd.c"
#include "ft_putchar_fd.c"
#include "ft_strlen.c"

int	main(void)
{
	char *str;

	str = ft_substr("Hello, World!", 0, 5);
	ft_putstr_fd(str, 1);
}
*/
