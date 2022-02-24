/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:34:44 by dthalman          #+#    #+#             */
/*   Updated: 2022/02/09 12:25:24 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_apply_status(t_philo *philo, enum e_state state)
{
	long	time;

	pthread_mutex_lock(&philo->table->print_mutex);
	time = (ft_gettime() - philo->table->start_time);
	philo->state = state;
	philo->last_chstatus = time;
	if (state == meal_finished && !philo->end)
	{
		philo->last_eat = time;
		philo->time_to_eat++;
	}
	if (philo->state == died)
		ft_print_status(philo, time);
	else
	{
		if (!philo->end)
			ft_print_status(philo, time);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	ft_print_status(t_philo *philo, long time)
{
	if (philo->state == take_fork)
		printf("\033[32m%6ld\033[0m %d has taken a fork\n", time,
			philo->number);
	if (philo->state == eating)
		printf("\033[32m%6ld\033[0m %d is eating\n", time, philo->number);
	if (philo->state == sleeping)
		printf("\033[32m%6ld\033[0m %d is sleeping\n", time, philo->number);
	if (philo->state == thinking)
		printf("\033[32m%6ld\033[0m %d thinking\n", time, philo->number);
	if (philo->state == died)
		printf("\033[32m%6ld\033[0m %d died\n", time, philo->number);
}

void	ft_philo_pick_fork(t_philo *philo)
{
	if (philo->number % 2)
	{
		pthread_mutex_lock(philo->fork_left);
		ft_apply_status(philo, take_fork);
		pthread_mutex_lock(philo->fork_right);
		ft_apply_status(philo, take_fork);
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		ft_apply_status(philo, take_fork);
		pthread_mutex_lock(philo->fork_left);
		ft_apply_status(philo, take_fork);
	}
}

void	*ft_philo_work(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	ft_apply_status(philo, thinking);
	usleep(philo->number * 100);
	while (!philo->end)
	{
		ft_philo_pick_fork(philo);
		ft_apply_status(philo, eating);
		usleep(philo->table->param->time_to_eat * 1000);
		ft_apply_status(philo, meal_finished);
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		if (philo->table->param->number_of_times_eat > 0
			&& philo->time_to_eat >= philo->table->param->number_of_times_eat)
			philo->end = 1;
		ft_apply_status(philo, sleeping);
		usleep(philo->table->param->time_to_sleep * 1000);
		ft_apply_status(philo, thinking);
		usleep(philo->number * 100);
	}
	return (arg);
}
