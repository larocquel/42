/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:27:12 by leoaguia          #+#    #+#             */
/*   Updated: 2025/05/04 17:18:32 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_message(char c)
{
	static char	*message;
	char		*char_str;
	char		*temp;

	if (c == '\0')
	{
		ft_printf("%s\n", message);
		free(message);
		message = NULL;
	}
	else
	{
		char_str = malloc(2 * sizeof(char));
		if (!char_str)
			return ;
		char_str[0] = c;
		char_str[1] = '\0';
		if (!message)
			message = ft_strdup("");
		temp = ft_strjoin(message, char_str);
		free(message);
		message = temp;
		free(char_str);
	}
}

void	handle_signal(int signal)
{
	static int	i;
	static int	c;

	if (signal == SIGUSR1)
		c = c | (1 << i);
	i++;
	if (i == 8)
	{
		handle_message(c);
		i = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void) av;
	if (ac != 1)
	{
		ft_printf("(Error) Usage: ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID: %i\n", pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
}
