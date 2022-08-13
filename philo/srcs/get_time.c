/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:55:34 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/13 11:47:47 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	get_time_and_print_it(t_indiv_data *philos_data)
{
	long int	time_elapsed;

	pthread_mutex_lock(&philos_data[0 - philos_data->philo_id - 1].global_data
		.time_mutex);
	gettimeofday(&philos_data->time.end, NULL);
	time_elapsed
		= ((philos_data->time.end.tv_sec
				- philos_data->time.start.tv_sec) * 1000000
			+ (philos_data->time.end.tv_usec
				- philos_data->time.start.tv_usec)) / 1000;
	printf("%ld ", time_elapsed);
	pthread_mutex_unlock(&philos_data[0 - philos_data->philo_id - 1].global_data
		.time_mutex);
}
