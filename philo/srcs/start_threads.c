/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:45:11 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/05 17:25:11 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	*start_routine(void *received_args)
{
	t_indiv_data	*philos_data;

	philos_data = (t_indiv_data *) received_args;
	philos_data->fork = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philos_data->fork, NULL);
	start_simulation(&philos_data[philos_data->philo_id - 1]);
	//pb sur la ligne d au dessus, la struct du philo envoyée ne contient pas les bonnes infos
	free(philos_data->fork);
	return (NULL);
}

void	init_struc(t_indiv_data *philos_data, long long *args)
{
	int	i;

	i = 0;
	while (i < args[0])
	{
		philos_data[i].global_data.nb_of_philosophers = args[0];
		philos_data[i].global_data.time_to_die = args[1];
		philos_data[i].global_data.time_to_eat = args[2];
		philos_data[i].global_data.time_to_sleep = args[3];
		philos_data[i].global_data.nb_of_times_philo_must_eat = 0;
		philos_data[i].nb_of_times_ate = 0;
		philos_data[i].time_alive = 0;
		philos_data[i].philo_id = 0;
		philos_data[i].own_fork = 0;
		philos_data[i].neighbour_fork = 0;
		philos_data[i].time.time_elapsed = 0;
		i++;
	}
}

void	start_threads(long long *args, int nb_args, t_indiv_data *philos_data)
{
	pthread_t		*id;
	int				i;
	int				trigger;

	trigger = 0;
	i = 0;
	id = malloc(sizeof(pthread_t) * philos_data[0].global_data.nb_of_philosophers);
	init_struc(philos_data, args);
	if (nb_args == 5)
	{
		if (trigger == 0)
		{
			while (i++ < philos_data[0].global_data.nb_of_philosophers)
				philos_data[i].global_data.nb_of_times_philo_must_eat = args[4];
			trigger = 1;
			i = 0;
		}
	}
	free(args);
	while (i < philos_data[0].global_data.nb_of_philosophers)
	{
		philos_data[i].philo_id = i;
		pthread_create(&id[i], NULL, &start_routine, (void *)&philos_data[i]);
		usleep(100);
		i++;
	}
	i = 0;
	while (i < philos_data[0].global_data.nb_of_philosophers)
	{
		pthread_join(id[i], NULL);
		i++;
	}
	pthread_join(*id, NULL);
	free(philos_data);
	free(id);
}
