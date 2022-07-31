/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:45:11 by blevrel           #+#    #+#             */
/*   Updated: 2022/07/31 14:59:27 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	*start_routine(void *received_args)
{
	int	i;

	i = 0;
	pthread_mutex_t	**forks;
	t_all_philos	*philos_data;

	philos_data = (t_all_philos *) received_args;
	forks = malloc(sizeof(pthread_mutex_t *) * philos_data->nb_of_philosophers);
	if (!forks)
		return (NULL);
	while (i < philos_data->nb_of_philosophers)
	{
		forks[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(forks[i], NULL);
		i++;
	}
	free_all_mutexes(forks, philos_data->nb_of_philosophers);
	start_simulation(forks, philos_data);
	pthread_exit(NULL);
}

void	free_all_mutexes(pthread_mutex_t **forks, int nb_philos)
{
	int	i;

	i = 0;
	while (i < nb_philos)
	{
		free(forks[i]);
		i++;
	}
	free(forks);
}

void	init_struc(t_all_philos *philos_data, long long *args)
{
	int	i;

	i = 0;
	philos_data->nb_of_philosophers = args[0];
	philos_data->time_to_die = args[1];
	philos_data->time_to_eat = args[2];
	philos_data->time_to_sleep = args[3];
	philos_data->i = 0;
	philos_data->time_elapsed = 0;
	while (i < philos_data->nb_of_philosophers)
	{
		philos_data->indiv_data[i].nb_of_times_ate = 0;
		philos_data->indiv_data[i].time_slept = 0;
		philos_data->indiv_data[i].time_eating = 0;
		philos_data->indiv_data[i].time_alive = 0;
		philos_data->indiv_data[i].philo_id = i;
		philos_data->indiv_data[i].right_fork = 0;
		philos_data->indiv_data[i].left_fork = 0;
		i++;
	}
}

void	start_threads(long long *args, int nb_args, t_all_philos philos_data)
{
	pthread_t		id;
	int				i;
	int				trigger;

	trigger = 0;
	i = 0;
	philos_data.indiv_data = malloc(sizeof(t_data) * args[0]);
	init_struc(&philos_data, args);
	if (nb_args == 5)
	{
		if (trigger == 0)
		{
			philos_data.nb_of_times_philo_must_eat = args[4];
			trigger = 1;
		}
		//faire passer dans une fonction qui verifie si ils ont mangé le nombre de fois requis
	}
	free(args);
	free(philos_data.indiv_data);
	while (i < philos_data.nb_of_philosophers)
	{
		philos_data.i = i;
		pthread_create(&id, NULL, &start_routine, (void *)&philos_data);
		i++;
		pthread_join(id, NULL);
	}
}
