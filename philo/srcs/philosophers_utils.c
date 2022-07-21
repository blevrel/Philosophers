/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:13:13 by blevrel           #+#    #+#             */
/*   Updated: 2022/07/21 14:47:04 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == '-' && (str[i + 1] > '0' && str[i + 1] < '9'))
			return (-1);
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atol(const char *nptr)
{
	int			i;
	long long	sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-' && i++ >= 0)
		sign = -1;
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (nptr[i] - 48);
		while (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		{
			res = (res * 10) + nptr[i + 1] - 48;
			i++;
		}
		return (res * sign);
	}
	return (0);
}

int	ft_isint(long long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	else
		return (0);
}
