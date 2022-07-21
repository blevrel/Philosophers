/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:50:41 by blevrel           #+#    #+#             */
/*   Updated: 2022/07/21 15:27:39 by blevrel          ###   ########.fr       */
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

	tab = malloc(nb_args * sizeof(long long));
	while (i < nb_args)
	{
		nb = ft_atol(args[i]);
		if (ft_isint(nb) == 0)
			tab[i] = nb;
		else
		{
			free(tab);
			exit(write(2, "Incorrect argument value\n", 25));
		}
		i++;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	long long	*args;

	if (argc == 5)
	{
		args = verify_args(argc, argv);
		//without optional argument
	}
	else if (argc == 6)
	{
		args = verify_args(argc, argv);
		//with optional argument
	}
	else
	{
		printf("Error\nArguments must be : number_of_philosophers, ");
		printf("time_to_die, time_to_eat, time_to_sleep, ");
		printf("[number_of_times_each_philosopher_must_eat] (optional)\n");
		return (-1);
	}
	free(args);
	return (0);
}
