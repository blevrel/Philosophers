/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_multithreading.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:47:48 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/27 17:12:22 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	func(int *arg)
{
	printf("Valeur de i à l'intérieur du thread : %d\n", (int)*arg);
	arg++;
	pthread_exit(arg);
}

int	main()
{
	int	i;
	pthread_t threads;
	int	*ptr;

	printf("Valeur initiale de i : ");
	scanf("%d", &i);
	pthread_create(&threads, NULL, func, i);
	pthread_join(threads, (void*)&ptr);
	printf("Valeur de i apres : %i\n", *ptr);
}
