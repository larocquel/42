/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:04:14 by leoaguia          #+#    #+#             */
/*   Updated: 2026/02/20 03:36:52 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Handles the eating phase and fork acquisition.
- To prevent circular deadlocks:
- even IDs lock right -> left.
- odd  IDs lock left -> right.
- Safely updates the last_meal timestamp and increments the meal count.
- Unlocks both forks after eating duration.
*/
void	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_status("has taken a fork", philo);
		pthread_mutex_lock(philo->l_fork);
		print_status("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_status("has taken a fork", philo);
		pthread_mutex_lock(philo->r_fork);
		print_status("has taken a fork", philo);
	}
	pthread_mutex_lock(&philo->table->meal_mtx);
	philo->last_meal = get_time();
	philo->meals_c++;
	pthread_mutex_unlock(&philo->table->meal_mtx);
	print_status("is eating", philo);
	ft_usleep(philo->table->time_eat, philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

/*
Handles the sleeping phase.
- Prints the status
- Delays the thread for the specified sleep duration.
*/
void	sleeping(t_philo *philo)
{
	print_status("is sleeping", philo);
	ft_usleep(philo->table->time_sleep, philo);
}

/*
Handles the thinking phase and prevents starvation in odd-numbered tables.
- Prints the thinking status safely.
- Calculates a dynamic think time based on eat and sleep durations.
- Forces a precise delay to prevent philosophers from stealing forks out of turn.
*/
void	thinking(t_philo *philo)
{
	int	time_think;

	print_status("is thinking", philo);
	if (philo->table->nb_philos % 2 != 0)
	{
		time_think = (philo->table->time_eat * 2) - philo->table->time_sleep;
		if (time_think > 0)
			ft_usleep(time_think, philo);
	}
}

/*
Safely updates the simulation's death status.
- Locks the dead_mtx to prevent data races.
- Sets the global dead_flag to 1, signaling all threads to stop.
*/
void	killer(t_table *table)
{
	pthread_mutex_lock(&table->dead_mtx);
	table->dead_flag = 1;
	pthread_mutex_unlock(&table->dead_mtx);
}
