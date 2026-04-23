/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:43:59 by leoaguia          #+#    #+#             */
/*   Updated: 2024/10/20 11:59:38 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]) == 1)
			count++;
		++i;
	}
	return (count);
}
/*
#include <stdio.h>

int starts_with_a(char *str)
{
    if (str[0] == 'a' || str[0] == 'A')
	{
		printf("%s\n", str);
        return (1);
	}
    return (0);
}

int main(void)
{
    char *tab[] ={"amor","Aristoteles","arco","carro","nada", "42", NULL};
	int count = ft_count_if(tab, &starts_with_a);

	printf("Number of strings starting with 'a' or 'A': %d\n", count);

    return (0);
}
*/
