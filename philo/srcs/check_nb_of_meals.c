/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_of_meals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 10:22:54 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/09 14:24:45 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philosophers.h"

int	check_nb_of_meals(t_indiv_data *philos_data)
{
	if (philos_data->nb_of_meals == philos_data->global_data
		.nb_of_times_philo_must_eat)
		return (1);
	return (0);
}
