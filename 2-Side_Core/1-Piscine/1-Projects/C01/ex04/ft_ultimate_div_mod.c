/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:35:31 by leoaguia          #+#    #+#             */
/*   Updated: 2024/09/09 19:28:05 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *a / *b;
	*b = temp % *b;
}
/*
#include <stdio.h>

int	main(void)
{
	int	p1 = 42;
	int	p2 = 2;
	
	printf("Before\np1: %i, p2: %i\n\n", p1, p2);

	ft_ultimate_div_mod(&p1, &p2);

	printf("After\np1: %i, p2: %i\n", p1, p2);
}
*/
