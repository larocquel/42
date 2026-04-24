/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 21:47:20 by leoaguia          #+#    #+#             */
/*   Updated: 2026/02/20 03:17:07 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Basic string length and standard error output function.
- Writes custom error messages directly to STDERR (file descriptor 2).
*/
int	print_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, str, len);
	return (1);
}

/*
Prints philosopher status changes safely.
- Locks write_mtx to prevent terminal output garbling.
- Checks dead_flag inside a mutex to ensure no msgs are printed after a death.
*/
void	print_status(char *str, t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->table->write_mtx);
	time = get_time() - philo->start_time;
	pthread_mutex_lock(&philo->table->dead_mtx);
	if (philo->table->dead_flag == 0)
		printf("%lld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->table->dead_mtx);
	pthread_mutex_unlock(&philo->table->write_mtx);
}

/*
Gets the current time in milliseconds.
- Converts output from gettimeofday into a unified millisecond format.
*/
long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/*
Improved usleep function
- Splits the sleep target into smaller chunks (500us = 0.5ms).
- Allows immediate thread termination, by constantly checking if a philo died.
*/
int	ft_usleep(long long time, t_philo *philo)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < time)
	{
		pthread_mutex_lock(&philo->table->dead_mtx);
		if (philo->table->dead_flag == 1)
		{
			pthread_mutex_unlock(&philo->table->dead_mtx);
			return (1);
		}
		pthread_mutex_unlock(&philo->table->dead_mtx);
		usleep(500);
	}
	return (0);
}

/*
Converts ASCII string inputs into integers.
- Handles standard whitespace, signs, and extracts numbers.
*/
int	ft_atoi(const char *str)
{
	long	number;
	int		sign;
	int		i;

	number = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (sign * number);
}
