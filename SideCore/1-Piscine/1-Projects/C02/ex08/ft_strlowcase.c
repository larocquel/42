/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:59:58 by leoaguia          #+#    #+#             */
/*   Updated: 2024/09/12 14:40:52 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
/*
#include <unistd.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "KEEP SWIMMING!";
	ft_strlowcase(s1);
	write(1, s1, strlen(s1));
	write(1, "\n", 1);
}
*/
