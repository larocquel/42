/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:35:08 by leoaguia          #+#    #+#             */
/*   Updated: 2025/04/25 17:34:37 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
#include "ft_isalpha.c"
#include "ft_isdigit.c"

int	main(void)
{
	int x = 'A';
		printf("Mine    : %i\n", ft_isalnum(x));
		printf("Original: %i\n", isalnum(x));
}
*/
