/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:51:16 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/25 17:11:27 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_digit(long long n, int base, char specifier)
{
	char	*symbol;
	int		count;

	symbol = "0123456789abcdef";
	if (specifier == 'X')
		symbol = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_put_char('-');
		return (ft_put_digit(-n, base, specifier) + 1);
	}
	else if (n < base)
		return (ft_put_char(symbol[n]));
	else
	{
		count = ft_put_digit(n / base, base, specifier);
		return (count + ft_put_digit(n % base, base, specifier));
	}
}
