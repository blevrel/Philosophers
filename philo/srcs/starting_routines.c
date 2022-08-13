/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_routines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:25:15 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/13 13:34:15 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	*start_routine(void *received_args)
{
	t_indiv_data	*philos_data;

	philos_data = (t_indiv_data *) received_args;
	start_simulation(philos_data);
	return (NULL);
}

int	check_time_elapsed(long int time_elapsed, t_indiv_data *philos_data, int i)
{
	if (time_elapsed > philos_data->global_data.time_to_die)
	{
		pthread_mutex_lock(&philos_data[0].global_data.msg_mutex);
		if ((philos_data[i].nb_of_meals != philos_data[i].global_data
				.nb_of_times_philo_must_eat) || philos_data[i].global_data
			.nb_of_times_philo_must_eat == 0)
		{
			get_time_and_print_it(&philos_data[i]);
			printf("%d died\n", philos_data[i].philo_id);
		}
		i = 0;
		while (i < philos_data->global_data.nb_of_philosophers)
		{
			philos_data[i].dead = 1;
			i++;
		}
		pthread_mutex_unlock(&philos_data[0].global_data.msg_mutex);
		return (1);
	}
	return (0);
}

void	*check_death(void *received_args)
{
	int				i;
	t_indiv_data	*philos_data;
	long int		time_elapsed;
	struct timeval	end;

	i = 0;
	philos_data = (t_indiv_data *) received_args;
	if (philos_data->global_data.nb_of_philosophers == 1)
		return (NULL);
	while (1)
	{
		if (i == philos_data->global_data.nb_of_philosophers)
			i = 0;
		pthread_mutex_lock(&philos_data[0].global_data.time_mutex);
		gettimeofday(&end, NULL);
		time_elapsed = ((end.tv_sec
					- philos_data[i].time.last_meal.tv_sec) * 1000000
				+ (end.tv_usec
					- philos_data[i].time.last_meal.tv_usec)) / 1000;
		pthread_mutex_unlock(&philos_data[0].global_data.time_mutex);
		if (check_time_elapsed(time_elapsed, philos_data, i) == 1)
			return (NULL);
		i++;
	}
}
