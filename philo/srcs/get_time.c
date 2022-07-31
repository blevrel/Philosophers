/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:55:34 by blevrel           #+#    #+#             */
/*   Updated: 2022/07/31 17:31:01 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	get_time_and_print_it(t_all_philos *philos_data)
{
	gettimeofday(&philos_data->end, NULL);
	philos_data->time_elapsed = ((philos_data->end.tv_sec -
			philos_data->start.tv_sec) * 1000000 + (philos_data->end.tv_usec -
			philos_data->start.tv_usec)) / 1000;	
	printf("%d ", philos_data->time_elapsed);
}
