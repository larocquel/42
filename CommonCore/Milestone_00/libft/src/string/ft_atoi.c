/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:33:22 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 15:24:34 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
ft_atoi converts string in integer value
atoi = ASCII to integer
nptr: pointer to the string
*/

int	ft_atoi(const char *nptr)
{
	int	n;
	int	s;

	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	s = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			s = -1;
		nptr++;
	}
	n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + *nptr - '0';
		nptr++;
	}
	return (n * s);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n = ft_atoi("   -1234ab567");
	printf("%i\n", n);
}
*/
