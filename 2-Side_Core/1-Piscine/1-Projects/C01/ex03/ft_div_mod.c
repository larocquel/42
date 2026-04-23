/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:25:57 by leoaguia          #+#    #+#             */
/*   Updated: 2024/09/09 16:33:44 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>

int	main(void)
{
	int	n1 = 10;
	int	n2 = 2;
	int	d;
	int	m;

	ft_div_mod(n1, n2, &d, &m);

	printf("a: %i\nb: %i\n", n1, n2);
	printf("div: %i\nmod: %i\n", d, m);
}
*/
