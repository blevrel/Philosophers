/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:38:49 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/07 10:26:52 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_time
{
	struct timeval	start;
	struct timeval	end;
	struct timeval	last_meal;
	int				time_elapsed;
}				t_time;

typedef struct s_all_philos
{
	int				nb_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_times_philo_must_eat;
}				t_all_philos;

typedef struct s_indiv_data
{
	int				nb_of_meals;
	int				time_alive;
	int				philo_id;
	int				own_fork;
	int				neighbour_fork;
	pthread_mutex_t	*fork;
	t_all_philos	global_data;
	t_time			time;
}				t_indiv_data;

int			ft_str_is_numeric(char *str);
long long	ft_atol(const char *nptr);
int			ft_isint(long long nb);
long long	*char_tab_to_int_tab(char **args, int nb_args, int i);
void		start_threads(long long *args, int nb_args, t_indiv_data *philos_data);
void		init_struc(t_indiv_data *philos_data, long long *args);
void		*start_routine(void *received_args);
void		start_simulation(t_indiv_data *philos_data);
void		get_time_and_print_it(t_indiv_data *philos_data);
int			check_death(t_indiv_data *philos_data);
int			check_nb_of_meals(t_indiv_data *philos_data);

#endif
