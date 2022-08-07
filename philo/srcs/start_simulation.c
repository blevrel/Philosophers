/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:04:00 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/07 11:27:11 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	take_forks(t_indiv_data *philos_data)
{
	while (philos_data->own_fork != 1
		&& philos_data->neighbour_fork != 1)
	{
		if (pthread_mutex_lock(philos_data->fork) == 0)
		{
			philos_data->own_fork = 1;
			get_time_and_print_it(philos_data);
			printf("%d has taken a fork\n", philos_data->philo_id);
		}
		if (philos_data->philo_id
			!= philos_data->global_data.nb_of_philosophers
			&& pthread_mutex_lock(philos_data[1].fork) == 0)
		{
			philos_data->neighbour_fork = 1;
			get_time_and_print_it(philos_data);
			printf("%d has taken a fork\n", philos_data->philo_id);
		}
		else if (pthread_mutex_lock(philos_data[0 - (philos_data->global_data
						.nb_of_philosophers - 1)].fork) == 0)
		{
			philos_data->neighbour_fork = 1;
			get_time_and_print_it(philos_data);
			printf("%d has taken a fork\n", philos_data->philo_id);
		}
	}
}

void	eat_and_drop_forks(t_indiv_data *philos_data)
{
	get_time_and_print_it(philos_data);
	printf("%d is eating\n", philos_data->philo_id);
	usleep(philos_data->global_data.time_to_eat * 1000);
	gettimeofday(&philos_data->time.last_meal, NULL);
	pthread_mutex_unlock(philos_data->fork);
	if (philos_data->philo_id
		!= philos_data->global_data.nb_of_philosophers)
		pthread_mutex_unlock(philos_data[1].fork);
	else
		pthread_mutex_unlock(philos_data[0 - (philos_data->global_data
				.nb_of_philosophers - 1)].fork);
	philos_data->nb_of_meals++;
	philos_data->own_fork = 0;
	philos_data->neighbour_fork = 0;
	if (check_nb_of_meals(philos_data) == 1)
		pthread_exit(NULL);
}

void	ft_sleep(t_indiv_data *philos_data)
{
	get_time_and_print_it(philos_data);
	printf("%d is sleeping\n", philos_data->philo_id);
	usleep(philos_data->global_data.time_to_sleep * 1000);
	get_time_and_print_it(philos_data);
	printf("%d is thinking\n", philos_data->philo_id);
}

void	start_simulation(t_indiv_data *philos_data)
{
	while (1)
	{
		if (check_death(philos_data) == 1)
		{
			printf("%d died\n", philos_data->philo_id);
			exit(-1);
		}
		take_forks(philos_data);
		if (philos_data->own_fork == 1
			&& philos_data->neighbour_fork == 1)
		{
			eat_and_drop_forks(philos_data);
			ft_sleep(philos_data);
		}
	}
}
