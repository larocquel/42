/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:57:19 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/07 17:08:42 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
#include "ft_putstr_fd.c"
#include "ft_putchar_fd.c"

int	main(void)
{
	char	str[] = "HI!";

	ft_putendl_fd(str, 1);
}
*/
