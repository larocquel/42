/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:44:10 by leoaguia          #+#    #+#             */
/*   Updated: 2024/10/20 12:26:32 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

int	check_args(int argc)
{
	if (argc == 1)
	{
		ft_putstr(2, "File name missing.\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr(2, "Too many arguments.\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	c;
	int		file;

	if (!check_args(ac))
		return (0);
	file = open(av[1], O_RDONLY);
	if (file == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return (0);
	}
	if (file >= 0)
	{
		while (read(file, &c, 1) == 1)
			write(1, &c, 1);
	}
	close(file);
}
