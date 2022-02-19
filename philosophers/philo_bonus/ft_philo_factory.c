/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:34:44 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/30 16:44:35 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	ft_fork_factory(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->param->nb_of_philos);
	i = 0;
	while (i < table->param->nb_of_philos)
	{	
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	ft_philo_factory(t_table *table)
{
	int		i;

	table->philos = malloc(sizeof(t_philo) * table->param->nb_of_philos);
	ft_fork_factory(table);
	i = 0;
	while (i < table->param->nb_of_philos)
	{	
		table->philos[i].number = i;
		pthread_create (&(table->philos[i].thread), NULL, &ft_philo_work,
			&(table->philos[i]));
		table->philos[i].fork_left = &table->forks[i];
		table->philos[i].fork_right = &table->forks[(i + 1)
			% table->param->nb_of_philos];
		table->philos[i].state = sleeping;
		table->philos[i].time_to_eat = 0;
		table->philos[i].table = table;
		table->philos[i].last_eat = ft_gettime();
		table->philos[i].end = 0;
		usleep(100);
		i++;
	}
}

void	ft_philo_dispose(t_table *table)
{
	free(table->philos);
	free(table->forks);
}
