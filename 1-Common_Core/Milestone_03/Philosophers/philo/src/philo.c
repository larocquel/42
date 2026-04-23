/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:42:29 by leoaguia          #+#    #+#             */
/*   Updated: 2026/02/20 02:47:26 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Checks if the simulation is still running safely.
- Locks the dead_mtx to read the global dead_flag without race conditions.
- Returns 1 if everyone is alive, 0 if someone died.
*/
int	is_alive(t_philo *philo)
{
	int	is_dead;

	pthread_mutex_lock(&philo->table->dead_mtx);
	is_dead = philo->table->dead_flag;
	pthread_mutex_unlock(&philo->table->dead_mtx);
	return (!is_dead);
}

/*
Special routine for when there is only one philosopher.
- Takes the only available fork.
- Waits until death since there's no second fork to eat.
- Prevents immediate deadlocks in 1-philo edge cases.
*/
void	*solitary(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status("has taken a fork", philo);
	ft_usleep(philo->table->time_die, philo);
	pthread_mutex_unlock(philo->l_fork);
	return (NULL);
}

/*
Main thread lifecycle for each philosopher.
- If philo is alone at table, he goes to solitary ft
- Delays odd-numbered philosophers slightly to prevent initial deadlocks.
- Loops until death or meal target is reached:
 - eating, sleeping, and thinking
*/
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->table->nb_philos == 1)
		return (solitary(philo));
	if (philo->id % 2 != 0)
		ft_usleep(10, philo);
	while (is_alive(philo))
	{
		eating(philo);
		if (philo->table->meals_t > 0
			&& philo->meals_c >= philo->table->meals_t)
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

/*
Evaluates if a specific philosopher has starved.
- Safely reads the last_meal time using a mutex.
- Compares elapsed time against time_die.
*/
int	philo_died(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->table->meal_mtx);
	time = get_time() - philo->last_meal;
	if (time >= philo->table->time_die)
	{
		pthread_mutex_unlock(&philo->table->meal_mtx);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->meal_mtx);
	return (0);
}

/*
Grim Reaper function running in the main thread.
- Constantly loops through all philosophers checking for starvation.
- Checks if all philosophers have reached the required meal count.
- Sets the dead_flag and stops the simulation if either condition is met.
*/
int	monitor(t_table *table, t_philo *philos)
{
	int	i;
	int	all_ate;

	while (1)
	{
		i = -1;
		all_ate = 0;
		while (++i < table->nb_philos)
		{
			if (philo_died(&philos[i]))
			{
				print_status("died", &philos[i]);
				killer(table);
				return (1);
			}
			pthread_mutex_lock(&table->meal_mtx);
			if (philos[i].meals_c >= table->meals_t && table->meals_t != -1)
				all_ate++;
			pthread_mutex_unlock(&table->meal_mtx);
		}
		if (all_ate == table->nb_philos && table->meals_t != -1)
			return (killer(table), 1);
		usleep(1000);
	}
	return (0);
}
