/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:17:28 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/12 16:37:43 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	display_message(t_indiv_data *philos_data, int msg_to_print)
{
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
}

int	check_death_and_print_message(t_indiv_data *philos_data, int msg_to_print)
{
	pthread_mutex_lock(&philos_data[0 - (philos_data->philo_id - 1)].global_data
		.msg_mutex);
	if (philos_data->dead == 1)
	{
		if (philos_data->own_fork == 1)
			pthread_mutex_unlock(&philos_data->fork);
		if (philos_data->philo_id == philos_data->global_data
			.nb_of_philosophers && philos_data->neighbour_fork == 1)
			pthread_mutex_unlock(&philos_data[0 - (philos_data->philo_id - 1)]
				.fork);
		else if (philos_data->neighbour_fork == 1)
			pthread_mutex_unlock(&philos_data[1].fork);
		pthread_mutex_unlock(&philos_data[0 - (philos_data->philo_id - 1)]
			.global_data.msg_mutex);
		return (1);
	}
	display_message(philos_data, msg_to_print);
	return (0);
}

void	*print_error_msg(int msg_code)
{
	if (msg_code == NOT_NUM)
		printf("Argument is not a valid number\n");
	else if (msg_code == NEG)
		printf("Argument can't be negative\n");
	else if (msg_code == EMPTY)
		printf("Empty string is not a valid argument\n");
	else if (msg_code == ARGC)
	{
		printf("Error\nArguments must be : number_of_philosophers, ");
		printf("time_to_die, time_to_eat, time_to_sleep, ");
		printf("[number_of_times_each_philosopher_must_eat] (optional)\n");
	}
	else if (msg_code == NOT_VALID)
		printf("Incorrect argument value\n");
	return (NULL);
}
