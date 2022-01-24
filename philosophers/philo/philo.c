/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:34:44 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/22 14:34:44 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	ret;
	pthread_t thread;
	void	*thread_return;

	printf("PTHREAD_THREADS_MAX : %d\n", PTHREAD_THREADS_MAX);
 

	printf("run program\n");
	ret = pthread_create (&thread, NULL, &start_routine, NULL);
	printf("pthread_join\n");
	pthread_join (thread, &thread_return);
	printf("end\n");
}

void *start_routine(void *arg)
{
	printf("start_routine\n");
	return (arg);
}