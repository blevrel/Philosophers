/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:50:41 by blevrel           #+#    #+#             */
/*   Updated: 2022/07/31 14:04:28 by blevrel          ###   ########.fr       */
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
			exit(write(2, "Argument is not a number\n", 25));
		else if (ft_str_is_numeric(args[i]) == -1)
			exit(write(2, "Argument can't be negative\n", 27));
		else if (args[i][0] == '\0')
			exit(write(2, "Empty string is not a valid argument\n", 37));
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
			exit(write(2, "Incorrect argument value\n", 25));
		}
		i++;
		j++;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	long long		*args;
	t_all_philos	philos_data;

	gettimeofday(&philos_data.start, NULL);
	if (argc == 5)
	{
		args = verify_args(argc, argv);
		start_threads(args, argc - 1, philos_data);
	}
	else if (argc == 6)
	{
		args = verify_args(argc, argv);
		start_threads(args, argc - 1, philos_data);
	}
	else
	{
		printf("Error\nArguments must be : number_of_philosophers, ");
		printf("time_to_die, time_to_eat, time_to_sleep, ");
		printf("[number_of_times_each_philosopher_must_eat] (optional)\n");
		return (-1);
	}
	return (0);
}
