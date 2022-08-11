/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:21:29 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/11 16:22:29 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	one_philo(t_indiv_data *philos_data)
{
	usleep(philos_data->global_data.time_to_die * 1000);
	pthread_mutex_unlock(&philos_data->fork);
	get_time_and_print_it(philos_data);
	printf("%d has died\n", philos_data->philo_id);
	return (1);
}
