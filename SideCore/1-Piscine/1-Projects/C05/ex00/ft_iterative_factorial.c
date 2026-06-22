/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:34:28 by leoaguia          #+#    #+#             */
/*   Updated: 2024/09/22 12:48:47 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	f;

	if (nb < 0)
		return (0);
	f = 1;
	while (nb > 0)
		f *= nb--;
	return (f);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("-1! = %i\n", ft_iterative_factorial(-1));
	printf(" 0! = %i\n", ft_iterative_factorial(0));
	printf(" 1! = %i\n", ft_iterative_factorial(1));
	printf(" 2! = %i\n", ft_iterative_factorial(2));
	printf(" 5! = %i\n", ft_iterative_factorial(5));
	printf("10! = %i\n", ft_iterative_factorial(10));
}
*/
