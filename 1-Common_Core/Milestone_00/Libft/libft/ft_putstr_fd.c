/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:37:54 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 14:54:42 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}
/*
#include <fcntl.h> // to use open()
#include "ft_putchar_fd.c"

int	main(void)
{
	char	str[] = "Hello, World!\n";

	ft_putstr_fd(str, 1);

	ft_putstr_fd("This is an error test.\n", 2);

	int	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	ft_putstr_fd("Writing to a file.\n", fd);
	close(fd);
}
*/
