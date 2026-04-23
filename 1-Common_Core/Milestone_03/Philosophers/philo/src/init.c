/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:32:42 by leoaguia          #+#    #+#             */
/*   Updated: 2026/02/20 03:20:28 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Parses command-line arguments and stores them in the table structure.
- Validates that inputs are strictly positive numbers.
- Handles the optional 6th argument (meal count).
*/
int	parse_input(t_table *table, int ac, char **av)
{
	table->nb_philos = ft_atoi(av[1]);
	if (table->nb_philos <= 0)
		return (print_error("Error: Number of philosophers\n"), 1);
	table->time_die = ft_atoi(av[2]);
	if (table->time_die <= 0)
		return (print_error("Error: Time to die\n"), 1);
	table->time_eat = ft_atoi(av[3]);
	if (table->time_eat <= 0)
		return (print_error("Error: Time to eat\n"), 1);
	table->time_sleep = ft_atoi(av[4]);
	if (table->time_sleep <= 0)
		return (print_error("Error: Time to sleep\n"), 1);
	if (ac == 6)
	{
		table->meals_t = ft_atoi(av[5]);
		if (table->meals_t <= 0)
			return (print_error("Error: Meal count\n"), 1);
	}
	else
		table->meals_t = -1;
	return (0);
}

/*
Initializes the main table environment.
- Calls parse_input to setup basic data.
- Allocates memory for the fork mutex array.
- Initializes all required mutexes (forks, print, death, and meal tracking).
*/
int	init_table(t_table *table, int ac, char **av)
{
	int	i;

	table->dead_flag = 0;
	if (parse_input(table, ac, av))
		return (1);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philos);
	if (!table->forks)
		return (print_error("Error: Malloc forks\n"), 1);
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->write_mtx, NULL);
	pthread_mutex_init(&table->dead_mtx, NULL);
	pthread_mutex_init(&table->meal_mtx, NULL);
	return (0);
}

/*
Initializes individual philosopher structures.
- Allocates memory for the philosophers array.
- Sets initial IDs (1 to N), times, and links them to the shared table.
- Assigns left and right forks
- I used modular arithmetic to create a circular table.
- Counterclockwise direction
*/
t_philo	*init_philos(t_table *table)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * table->nb_philos);
	if (!philos)
		return (print_error("Error: Malloc philos\n"), NULL);
	i = 0;
	while (i < table->nb_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_c = 0;
		philos[i].start_time = get_time();
		philos[i].last_meal = get_time();
		philos[i].table = table;
		philos[i].l_fork = &table->forks[i];
		philos[i].r_fork = &table->forks[(i + 1) % table->nb_philos];
		i++;
	}
	return (philos);
}
