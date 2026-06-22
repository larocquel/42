/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:04:05 by leoaguia          #+#    #+#             */
/*   Updated: 2026/02/20 00:06:28 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Frees all allocated memory and destroys all mutexes safely.
- Destroys each fork mutex individually.
- Destroys the global table mutexes (write, dead, meal).
- Frees the dynamically allocated arrays.
*/
void	cleanup(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->write_mtx);
	pthread_mutex_destroy(&table->dead_mtx);
	pthread_mutex_destroy(&table->meal_mtx);
	free(table->forks);
	free(philos);
}

/*
Entry point of the program.
- Validates argument count.
- Initializes the shared table structure and mutexes.
- Initializes philosophers and creates their threads.
- Starts the monitoring system.
- Waits for all threads to finish (join) and cleans up.
*/
int	main(int ac, char **av)
{
	t_table	table;
	t_philo	*philos;
	int		i;

	if (ac != 5 && ac != 6)
		return (print_error("Error: Number of arguments\n"), 1);
	if (init_table(&table, ac, av))
		return (1);
	philos = init_philos(&table);
	if (!philos)
		return (1);
	i = 0;
	while (i < table.nb_philos)
	{
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		i++;
	}
	monitor(&table, philos);
	i = 0;
	while (i < table.nb_philos)
		pthread_join(philos[i++].thread, NULL);
	cleanup(&table, philos);
	return (0);
}
