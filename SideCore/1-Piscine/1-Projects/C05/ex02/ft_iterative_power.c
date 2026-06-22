/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:13:52 by leoaguia          #+#    #+#             */
/*   Updated: 2024/09/22 16:37:23 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	p;

	if (power < 0)
		return (0);
	p = 1;
	while (power > 0)
	{
		p *= nb;
		power--;
	}
	return (p);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_iterative_power(5, 2));
}
*/
