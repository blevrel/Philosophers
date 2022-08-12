/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:38:49 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/12 18:38:28 by blevrel          ###   ########.fr       */
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
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define NEG 1
# define NOT_NUM 2
# define EMPTY 3
# define ARGC 4
# define NOT_VALID 5

typedef struct s_time
{
	struct timeval	start;
	struct timeval	end;
	struct timeval	last_meal;
}				t_time;

typedef struct s_all_philos
{
	int				nb_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	pthread_mutex_t	msg_mutex;
	pthread_mutex_t	time_mutex;
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
	pthread_mutex_t	fork;
	int				dead;
	t_all_philos	global_data;
	t_time			time;
}				t_indiv_data;

int			ft_str_is_numeric(char *str);
long long	ft_atol(const char *nptr);
int			ft_isint(long long nb);
long long	*char_tab_to_int_tab(char **args, int nb_args, int i);
void		start_threads(long long *args, int nb_args,
				t_indiv_data *philos_data);
void		init_struc(t_indiv_data *philos_data, long long *args);
void		*start_routine(void *received_args);
void		start_simulation(t_indiv_data *philos_data);
void		get_time_and_print_it(t_indiv_data *philos_data);
int			check_nb_of_meals(t_indiv_data *philos_data);
int			check_death_and_print_message(t_indiv_data *philos_data, int msg_to_print);
void		*print_error_msg(int msg_code);
int			one_philo(t_indiv_data *philos_data);

#endif
