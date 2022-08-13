/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:04:00 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/13 13:21:32 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	take_neighbour_fork(t_indiv_data *philos_data)
{
	if (philos_data->philo_id
		!= philos_data->global_data.nb_of_philosophers
		&& pthread_mutex_lock(&philos_data[1].fork) == 0)
	{
		philos_data->neighbour_fork = 1;
		if (check_death_and_print_message(philos_data, FORK) == 1)
			return (1);
	}
	else if (pthread_mutex_lock(&philos_data[0 - (philos_data->global_data
					.nb_of_philosophers - 1)].fork) == 0)
	{
		philos_data->neighbour_fork = 1;
		if (check_death_and_print_message(philos_data, FORK) == 1)
			return (1);
	}
	return (0);
}

int	take_forks(t_indiv_data *philos_data)
{
	while (philos_data->own_fork != 1 && philos_data->neighbour_fork != 1)
	{
		if (pthread_mutex_lock(&philos_data->fork) == 0)
		{
			philos_data->own_fork = 1;
			if (check_death_and_print_message(philos_data, FORK) == 1)
				return (1);
			if (philos_data->global_data.nb_of_philosophers == 1)
				return (one_philo(philos_data));
		}
		if (take_neighbour_fork(philos_data) == 1)
			return (1);
	}
	return (0);
}

int	eat_and_drop_forks(t_indiv_data *philos_data)
{
	if (check_death_and_print_message(philos_data, EAT) == 1)
		return (1);
	pthread_mutex_lock(&philos_data[0 - (philos_data->philo_id - 1)]
		.global_data.time_mutex);
	gettimeofday(&philos_data->time.last_meal, NULL);
	pthread_mutex_unlock(&philos_data[0 - (philos_data->philo_id - 1)]
		.global_data.time_mutex);
	usleep(philos_data->global_data.time_to_eat * 1000);
	pthread_mutex_unlock(&philos_data->fork);
	if (philos_data->philo_id != philos_data->global_data.nb_of_philosophers)
		pthread_mutex_unlock(&philos_data[1].fork);
	else
		pthread_mutex_unlock(&philos_data[0 - (philos_data->global_data
				.nb_of_philosophers - 1)].fork);
	pthread_mutex_lock(&philos_data[0 - (philos_data->philo_id - 1)]
		.global_data.msg_mutex);
	philos_data->nb_of_meals++;
	pthread_mutex_unlock(&philos_data[0 - (philos_data->philo_id - 1)]
		.global_data.msg_mutex);
	philos_data->own_fork = 0;
	philos_data->neighbour_fork = 0;
	if (philos_data->global_data.nb_of_times_philo_must_eat != 0
		&& check_nb_of_meals(philos_data) == 1)
		return (1);
	return (0);
}

int	ft_sleep(t_indiv_data *philos_data)
{
	if (check_death_and_print_message(philos_data, SLEEP) == 1)
		return (1);
	usleep(philos_data->global_data.time_to_sleep * 1000);
	if (check_death_and_print_message(philos_data, THINK) == 1)
		return (1);
	return (0);
}

void	start_simulation(t_indiv_data *philos_data)
{
	while (1)
	{
		if (take_forks(philos_data) == 1)
			return ;
		if (philos_data->own_fork == 1 && philos_data->neighbour_fork == 1)
		{
			if (eat_and_drop_forks(philos_data) == 1)
				return ;
			if (ft_sleep(philos_data) == 1)
				return ;
		}
	}
}
