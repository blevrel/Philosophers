/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:04:00 by blevrel           #+#    #+#             */
/*   Updated: 2022/07/31 17:40:03 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"
void	take_forks()
{
	
}

void	start_simulation(pthread_mutex_t **forks, t_all_philos *philos_data)
{
	(void) forks;
	(void) philos_data;
	take_forks();
	//dans cette fonction, les philos vont essayer de prendre une ou deux fourchettes
	//puis ils dorment et se reveillent pour reessayer de reprendre des fourchettes

}
