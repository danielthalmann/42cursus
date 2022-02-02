/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:34:44 by dthalman          #+#    #+#             */
/*   Updated: 2022/02/02 14:11:16 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status(t_philo *philo, enum e_state state)
{
	long	time;

	philo->state = state;
	time = ft_gettime() / 1000;
	if (state == take_fork && !philo->end)
		printf("\033[32m%ld\033[0m %d has taken a fork\n", time, philo->number);
	if (state == eating && !philo->end)
		printf("\033[32m%ld\033[0m %d is eating\n", time, philo->number);
	if (state == sleeping && !philo->end)
		printf("\033[32m%ld\033[0m %d is sleeping\n", time, philo->number);
	if (state == thinking && !philo->end)
		printf("\033[32m%ld\033[0m %d thinking\n", time, philo->number);
	if (state == died)
		printf("\033[32m%ld\033[0m %d died\n", time, philo->number);
	if (state == meal_finished && !philo->end)
	{
		philo->last_eat = time * 1000;
		philo->time_to_eat++;
	}
}

void	ft_philo_pick_fork(t_philo *philo)
{
	if (philo->number % 2)
	{
		pthread_mutex_lock(philo->fork_left);
		ft_print_status(philo, take_fork);
		pthread_mutex_lock(philo->fork_right);
		ft_print_status(philo, take_fork);
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		ft_print_status(philo, take_fork);
		pthread_mutex_lock(philo->fork_left);
		ft_print_status(philo, take_fork);
	}
}

void	*ft_philo_work(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	ft_print_status(philo, thinking);
	while (!philo->end)
	{
		ft_philo_pick_fork(philo);
		ft_print_status(philo, eating);
		usleep(philo->table->param->time_to_eat * 1000);
		ft_print_status(philo, meal_finished);
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		if (philo->table->param->number_of_times_eat > 0
			&& philo->time_to_eat >= philo->table->param->number_of_times_eat)
		{
			philo->end = 1;
			ft_print_status(philo, died);
		}
		ft_print_status(philo, sleeping);
		usleep(philo->table->param->time_to_sleep * 1000);
		ft_print_status(philo, thinking);
	}
	return (arg);
}
