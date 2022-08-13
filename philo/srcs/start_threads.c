/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:45:11 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/13 13:45:53 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	init_struc(t_indiv_data *philos_data, long long *args)
{
	int	i;

	i = 0;
	pthread_mutex_init(&philos_data[0].global_data.msg_mutex, NULL);
	pthread_mutex_init(&philos_data[0].global_data.time_mutex, NULL);
	while (i < args[0])
	{
		philos_data[i].global_data.nb_of_philosophers = args[0];
		philos_data[i].global_data.time_to_die = args[1];
		philos_data[i].global_data.time_to_eat = args[2];
		philos_data[i].global_data.time_to_sleep = args[3];
		philos_data[i].global_data.nb_of_times_philo_must_eat = 0;
		philos_data[i].nb_of_meals = 0;
		philos_data[i].philo_id = i + 1;
		philos_data[i].own_fork = 0;
		philos_data[i].neighbour_fork = 0;
		philos_data[i].dead = 0;
		pthread_mutex_init(&philos_data[i].fork, NULL);
		i++;
	}
}

void	init_threads(long long *args, int nb_args, t_indiv_data *philos_data)
{
	pthread_t		*id;
	pthread_t		*death_checker;
	int				i;
	int				trigger;

	trigger = 0;
	i = -1;
	id = malloc(sizeof(pthread_t) * (args[0] + 1));
	death_checker = malloc(sizeof(pthread_t));
	if (id == NULL || death_checker == NULL)
		return ;
	init_struc(philos_data, args);
	if (nb_args == 5)
	{
		if (trigger == 0)
		{
			while (++i < philos_data->global_data.nb_of_philosophers)
				philos_data[i].global_data.nb_of_times_philo_must_eat = args[4];
			trigger = 1;
		}
	}
	start_threads(philos_data, death_checker, id);
}

void	start_threads(t_indiv_data *philos_data,
	pthread_t *death_checker, pthread_t *id)
{
	int	i;

	i = -1;
	while (++i < philos_data->global_data.nb_of_philosophers)
	{
		pthread_create(&id[i], NULL, &start_routine, (void *)&philos_data[i]);
		usleep(100);
	}
	pthread_create(death_checker, NULL, &check_death, (void *)&philos_data[0]);
	i = -1;
	pthread_join(*death_checker, NULL);
	while (++i < philos_data->global_data.nb_of_philosophers)
		pthread_join(id[i], NULL);
	free(id);
	free(death_checker);
}
