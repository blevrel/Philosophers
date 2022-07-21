/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:38:49 by blevrel           #+#    #+#             */
/*   Updated: 2022/07/21 15:27:48 by blevrel          ###   ########.fr       */
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

int			ft_str_is_numeric(char *str);
long long	ft_atol(const char *nptr);
int			ft_isint(long long nb);
long long	*char_tab_to_int_tab(char **args, int nb_args, int i);

#endif
