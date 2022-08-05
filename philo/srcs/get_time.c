/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:55:34 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/05 14:57:08 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	get_time_and_print_it(t_indiv_data *philos_data)
{
	gettimeofday(&philos_data->time.end, NULL);
	philos_data->time.time_elapsed =
		((philos_data->time.end.tv_sec
				- philos_data->time.start.tv_sec) * 1000000
			+ (philos_data->time.end.tv_usec
				- philos_data->time.start.tv_usec)) / 1000;
	printf("\033[1;31m");
	printf("%d ", philos_data->time.time_elapsed);
	printf("\033[0m");
}
