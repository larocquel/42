/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:47:57 by leoaguia          #+#    #+#             */
/*   Updated: 2024/09/18 00:26:07 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}
/*
int	main(void)
{
	ft_putnbr(123);	
	write(1, "\n", 1);
	ft_putnbr(-42);	
	write(1, "\n", 1);
	ft_putnbr(0);	
	write(1, "\n", 1);
	ft_putnbr(2147483647);	
	write(1, "\n", 1);
	ft_putnbr(-2147483648);	
	write(1, "\n", 1);
}
*/
