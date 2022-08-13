/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:50:41 by blevrel           #+#    #+#             */
/*   Updated: 2022/08/13 14:02:33 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

long long	*verify_args(int nb_args, char **args)
{
	int			i;
	long long	*tab;

	i = 1;
	while (i < nb_args)
	{
		if (ft_str_is_numeric(args[i]) == 0)
			return (print_error_msg(NOT_NUM));
		else if (ft_str_is_numeric(args[i]) == -1)
			return (print_error_msg(NEG));
		else if (args[i][0] == '\0')
			return (print_error_msg(EMPTY));
		else if (ft_strlen(args[i]) > 10)
			return (print_error_msg(NOT_VALID));
		i++;
	}
	i = 1;
	tab = char_tab_to_int_tab(args, nb_args, i);
	return (tab);
}

long long	*char_tab_to_int_tab(char **args, int nb_args, int i)
{
	long long	*tab;
	long long	nb;
	long long	j;

	j = 0;
	tab = malloc((nb_args - 1) * sizeof(long long));
	if (tab == NULL)
		return (NULL);
	while (i < nb_args)
	{
		nb = ft_atol(args[i]);
		if (ft_isint(nb) == 0)
			tab[j] = nb;
		else
		{
			free(tab);
			return (print_error_msg(NOT_VALID));
		}
		i++;
		j++;
	}
	return (tab);
}

void	init_time_structure(t_indiv_data *philos_data, long long nb_philos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	gettimeofday(&philos_data[j].time.start, NULL);
	gettimeofday(&philos_data[j].time.last_meal, NULL);
	while (++i < nb_philos)
	{
		philos_data[i].time.start = philos_data[j].time.start;
		philos_data[i].time.last_meal = philos_data[j].time.start;
	}
}

int	main(int argc, char **argv)
{
	long long		*args;
	t_indiv_data	*philos_data;

	if (argc != 5 && argc != 6)
	{
		print_error_msg(ARGC);
		return (-1);
	}
	args = verify_args(argc, argv);
	if (args == NULL)
		return (-1);
	philos_data = malloc(sizeof(t_indiv_data) * args[0]);
	if (philos_data == NULL)
		return (-1);
	init_time_structure(philos_data, args[0]);
	init_threads(args, argc - 1, philos_data);
	free(philos_data);
	free(args);
	return (0);
}
