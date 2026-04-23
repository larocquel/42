/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:56:04 by leoaguia          #+#    #+#             */
/*   Updated: 2024/10/17 19:14:28 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	arr = malloc(sizeof(int) * size);
	i = 0;
	while (min < max)
		arr[i++] = min++;
	return (arr);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 3)
		printf("Try with 2 parameters, please!\n");
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
