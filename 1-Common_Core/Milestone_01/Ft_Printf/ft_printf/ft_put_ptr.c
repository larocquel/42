/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:50:19 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/25 17:37:24 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_put_hex(n / 16);
	count += ft_put_char(base[n % 16]);
	return (count);
}

int	ft_put_ptr(unsigned long n)
{
	int	count;

	if (!n)
		return (ft_put_str("(nil)"));
	count = ft_put_str("0x");
	count += ft_put_hex(n);
	return (count);
}
