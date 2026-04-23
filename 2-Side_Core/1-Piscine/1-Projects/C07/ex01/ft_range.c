/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:06:37 by leoaguia          #+#    #+#             */
/*   Updated: 2024/09/23 20:45:25 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*array;

	if (min >= max)
		return (NULL);
	size = max - min;
	array = (int *)malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (min < max)
		array[i++] = min++;
	return (array);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{	
		printf("Try with 2 arguments, please!\n");
		return (1);
	}
	int	min = atoi(av[1]);
	int max = atoi(av[2]);
	int i = 0;
	int len = max - min;
	int *array = ft_range(min, max);
	while(i < len)
	{
		printf("%i ", array[i++]);
	}
}
*/
