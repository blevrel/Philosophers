/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:26:28 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/06 14:42:16 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	check_death(t_indiv_data *philos_data)
{
	gettimeofday(&philos_data->time.end, NULL);
	philos_data->time.time_elapsed
		= ((philos_data->time.end.tv_sec
				- philos_data->time.last_meal.tv_sec) * 1000000
			+ (philos_data->time.end.tv_usec
				- philos_data->time.last_meal.tv_usec)) / 1000;
	if (philos_data->time.time_elapsed > philos_data->global_data.time_to_die)
		return (1);
	return (0);
}
