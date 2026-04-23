/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:54:33 by leoaguia          #+#    #+#             */
/*   Updated: 2024/09/09 19:26:28 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
#include <stdio.h>

int	main(void)
{
	int	n1 = 42, n2 = 100;

	printf("Before\nn1: %i\nn2: %i\n\n", n1, n2);
	ft_swap(&n1, &n2);
	printf("After\nn1: %i\nn2: %i\n", n1, n2);
}
*/
