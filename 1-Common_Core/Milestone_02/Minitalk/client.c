/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:27:14 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/04 18:21:17 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bits(int pid, int byte, int len)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (byte & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (1);
		}
		byte >>= 1;
		if (len <= 1000)
			usleep(500);
		else
			usleep(1000);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int				pid;
	int				i;
	int				len;

	if (ac != 3)
	{
		ft_printf("(ERROR) Usage: ./client (PID) 'Message'\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	len = ft_strlen(av[2]);
	i = 0;
	while (av[2][i])
	{
		if (send_bits(pid, av[2][i++], len) == 1)
			return (ft_printf("Kill returned -1, probably invalid PID.\n"));
	}
	send_bits(pid, '\0', len);
	return (0);
}
