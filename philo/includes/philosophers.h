/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:38:49 by blevrel           #+#    #+#             */
/*   Updated: 2022/07/31 14:58:31 by blevrel          ###   ########.fr       */
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

typedef struct s_data
{
	int			nb_of_times_ate;
	int			time_slept;
	int			time_eating;
	int			time_alive;
	int			philo_id;
	int			right_fork;
	int			left_fork;
}				t_data;

typedef struct s_all_philos
{
	int				nb_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_times_philo_must_eat;
	int				i;
	struct timeval	start;
	struct timeval	end;
	int				time_elapsed;
	t_data			*indiv_data;
}				t_all_philos;

int			ft_str_is_numeric(char *str);
long long	ft_atol(const char *nptr);
int			ft_isint(long long nb);
long long	*char_tab_to_int_tab(char **args, int nb_args, int i);
void		start_threads(long long *args, int nb_args, t_all_philos philos_data);
void		init_struc(t_all_philos *philos_data, long long *args);
void		*start_routine(void *received_args);
void		free_all_mutexes(pthread_mutex_t **forks, int nb_philos);
void		start_simulation(pthread_mutex_t **forks, t_all_philos *philos_data);
void		get_time_and_print_it(t_all_philos *philos_data);

#endif
