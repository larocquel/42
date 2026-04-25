/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:32:38 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:13:34 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void ft_toloweri(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'A' && *c <= 'Z')
        *c += 32;
}
#include <stdio.h>

int main(void)
{
    char str[] = "HELLO, WORLD!";

    ft_striteri(str, ft_toloweri);
    printf("%s\n", str);
}
*/
