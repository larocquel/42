/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:42:14 by leoaguia          #+#    #+#             */
/*   Updated: 2026/02/20 03:16:43 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_table
{
	int				nb_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meals_t;
	int				dead_flag;
	pthread_mutex_t	write_mtx;
	pthread_mutex_t	dead_mtx;
	pthread_mutex_t	meal_mtx;
	pthread_mutex_t	*forks;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				meals_c;
	long long		start_time;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_table			*table;
}	t_philo;

// main.c
void		cleanup(t_table *table, t_philo *philos);
int			main(int ac, char **av);

// init.c
int			parse_input(t_table *table, int ac, char **av);
int			init_table(t_table *table, int ac, char **av);
t_philo		*init_philos(t_table *table);

// philo.c
int			is_alive(t_philo *philo);
void		*solitary(t_philo *philo);
void		*routine(void *arg);
int			philo_died(t_philo *philo);
int			monitor(t_table *table, t_philo *philos);

// actions.c
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		killer(t_table *table);

// utils.c
int			print_error(char *str);
void		print_status(char *str, t_philo *philo);
long long	get_time(void);
int			ft_usleep(long long time, t_philo *philo);
int			ft_atoi(const char *str);

#endif