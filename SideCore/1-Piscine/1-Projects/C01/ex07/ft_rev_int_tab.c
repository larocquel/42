/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:36:42 by leoaguia          #+#    #+#             */
/*   Updated: 2024/09/09 18:27:31 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	s;
	int	i;

	s = size - 1;
	i = 0;
	while (i <= (s / 2))
	{
		temp = tab[i];
		tab[i] = tab[s - i];
		tab[s - i] = temp;
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int	array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int	size = 8;
	int	i = 0;

	// Prints the original array	
	while(i < size)
		printf("%i", array[i++]);
	printf("\n");
	
	// Calls the function to invert the array
	ft_rev_int_tab(array, size);

	// Prints the reverse array
	i = 0;
	while(i < size)
		printf("%i", array[i++]);
	printf("\n");
}
*/
