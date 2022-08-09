/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:17:28 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/09 17:09:56 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	print_message(t_indiv_data *philos_data, int msg_to_print)
{
	static int		dead = 0;

	pthread_mutex_lock(&philos_data[0 - (philos_data->philo_id - 1)].global_data
		.msg_mutex);
	if (dead == 1)
	{
		pthread_mutex_unlock(&philos_data[0 - (philos_data->philo_id - 1)]
			.global_data.msg_mutex);
		return (1);
	}
	if (check_death(philos_data) == 1)
	{
		dead = 1;
		printf("%d has died\n", philos_data->philo_id);
		pthread_mutex_unlock(&philos_data[0 - (philos_data->philo_id - 1)]
			.global_data.msg_mutex);
		return (1);
	}
	if (msg_to_print == FORK)
	{
		get_time_and_print_it(philos_data);
		printf("%d has taken a fork\n", philos_data->philo_id);
	}
	else if (msg_to_print == EAT)
	{
		get_time_and_print_it(philos_data);
		printf("%d is eating\n", philos_data->philo_id);
	}
	else if (msg_to_print == SLEEP)
	{
		get_time_and_print_it(philos_data);
		printf("%d is sleeping\n", philos_data->philo_id);
	}
	else if (msg_to_print == THINK)
	{
		get_time_and_print_it(philos_data);
		printf("%d is thinking\n", philos_data->philo_id);
	}
	pthread_mutex_unlock(&philos_data[0 - (philos_data->philo_id - 1)]
		.global_data.msg_mutex);
	return (0);
}
