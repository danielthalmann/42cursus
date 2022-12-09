/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_factory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:34:44 by dthalman          #+#    #+#             */
/*   Updated: 2022/02/09 10:32:27 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief initialise le mutex d'impression
 * 
 * @param table 
 * @return int si tout s'est bien passé, le retour est 1. Lors d'une erreur
 * on retourne 0.
 */
int	ft_print_mutex_factory(t_table *table)
{
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (0);
	return (1);
}

/**
 * @brief Retourne le temps en microseconde
 * 
 * @return long 
 */
long	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/**
 * @brief Création des mutex pour les fourchettes
 * 
 * @param table 
 * @return int si tout s'est bien passé, le retour est 1. Lors d'une erreur
 * on retourne 0.
 */
int	ft_fork_factory(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->param->nb_of_philos);
	if (!table->forks)
		return (0);
	i = 0;
	while (i < table->param->nb_of_philos)
	{	
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Création des threads des philosophes
 * 
 * @param table 
 * @return int si tout s'est bien passé, le retour est 1. Lors d'une erreur
 * on retourne 0.
 */
int	ft_philo_factory(t_table *table)
{
	int		i;

	table->philos = malloc(sizeof(t_philo) * table->param->nb_of_philos);
	if (!table->philos || !ft_fork_factory(table))
		return (0);
	i = 0;
	while (i < table->param->nb_of_philos)
	{	
		table->philos[i].number = i;
		if (pthread_create (&(table->philos[i].thread), NULL, &ft_philo_work,
				&(table->philos[i])))
			return (0);
		table->philos[i].fork_left = &table->forks[i];
		table->philos[i].fork_right = &table->forks[(i + 1)
			% table->param->nb_of_philos];
		table->philos[i].state = sleeping;
		table->philos[i].time_to_eat = 0;
		table->philos[i].table = table;
		table->philos[i].last_eat = (ft_gettime() - table->start_time);
		table->philos[i].end = 0;
		usleep(100);
		i++;
	}
	return (1);
}

void	ft_philo_dispose(t_table *table)
{
	int	i;

	free(table->philos);
	i = 0;
	while (i < table->param->nb_of_philos)
	{	
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
}
