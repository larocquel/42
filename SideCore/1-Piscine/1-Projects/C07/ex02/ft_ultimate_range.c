/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:53:59 by leoaguia          #+#    #+#             */
/*   Updated: 2024/09/23 20:43:13 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	array = (int *) malloc(sizeof(int) * size);
	if (!array)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < size)
		array[i++] = min++;
	*range = array;
	return (size);
}
/*
#include <stdio.h>

int main(void)
{
	int *array;
	int size;
	int min = -1;
	int max = 10;
	int i;

	size = ft_ultimate_range(&array, min, max);
	if (size == -1)
	{
		printf("Memory allocation failed\n");
		return 1;
	}
	else if (size == 0)
	{
		printf("Invalid range\n");
		return 1;
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	free(array);
	return 0;
}
*/
