/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:43:17 by leoaguia          #+#    #+#             */
/*   Updated: 2024/10/20 11:57:18 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
#include <unistd.h>
void    ft_putnbr(int nb)
{
    char    c;

    if (nb > 9)
        ft_putnbr(nb / 10);
    c = nb % 10 + '0';
    write(1, &c, 1);
	write(1, "\n", 1);
}

void    ft_foreach(int *tab, int length, void (*f)(int));

int main(void)
{
    int arr[] = {8, 9, 10, 11, 12};
    ft_foreach(arr, 5, &ft_putnbr);
    return (0);
}
*/
