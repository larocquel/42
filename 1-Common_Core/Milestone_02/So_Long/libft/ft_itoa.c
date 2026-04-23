/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:44:25 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 15:35:18 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_aux(long *n, int *neg, int *size)
{
	long	temp;

	temp = *n;
	if (temp < 0)
	{
		*neg = 1;
		*n = -(*n);
		temp = -temp;
	}
	else if (temp == 0)
		*size = 1;
	while (temp != 0)
	{
		temp = temp / 10;
		(*size)++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		size;
	int		neg;
	int		i;

	size = 0;
	neg = 0;
	nb = n;
	ft_aux(&nb, &neg, &size);
	str = malloc(sizeof(char) * (size + 1 + neg));
	if (!str)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	i = size - 1 + neg;
	while (i >= neg)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	str[size + neg] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(123));
	printf("%s\n", ft_itoa(-123));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
}
*/
