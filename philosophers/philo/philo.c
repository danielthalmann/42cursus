/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:34:44 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/30 16:51:30 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_parameter	param;
	t_table		table;
	int			i;

	if (!ft_load_parameter(&param, argc, argv))
		return (0);
	table.param = &param;
	ft_philo_factory(&table);
	ft_philo_wait_end(&table);
	ft_philo_dispose(&table);
}

int	ft_all_died(t_philo *philos, int len)
{
	while (len--)
	{
		if (!philos[len].end)
			return (0);
	}
	return (1);
}

void	ft_philo_end(t_table *table)
{
	int		i;

	i = table->param->nb_of_philos;
	while (i--)
	{
		table->philos[i].end = 1;
		pthread_join (table->philos[i].thread, NULL);
	}
}

void	ft_philo_wait_end(t_table *table)
{
	int		i;
	int		end;

	end = 0;
	while (!end)
	{			
		i = table->param->nb_of_philos;
		while (i--)
		{
			if (!table->philos[i].end && table->philos[i].state != eating
				&& ft_gettime() - table->philos[i].last_eat
				> table->param->time_to_die * 1000)
			{
				ft_print_status(&table->philos[i], died);
				table->philos[i].end = 1;
				pthread_detach(table->philos[i].thread);
				end = 1;
			}
			if (ft_all_died(table->philos, table->param->nb_of_philos))
				end = 1;
		}
		usleep(10000);
	}
	ft_philo_end(table);
}

/**
 * @brief Charge les paramètres de la commande
 * 
 * @param param 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	ft_load_parameter(t_parameter *param, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("The number of arguments is invalid.\n\n");
		printf("type : %s [nb_of_philos] [time_to_die] ", argv[0]);
		printf("[time_to_eat] [time_to_sleep]");
		printf("\n optional  : [number_of_times_eat]\n\n");
		return (0);
	}
	param->nb_of_philos = ft_atoi_pos(argv[1]);
	param->time_to_die = ft_atoi_pos(argv[2]);
	param->time_to_eat = ft_atoi_pos(argv[3]);
	param->time_to_sleep = ft_atoi_pos(argv[4]);
	if (argc == 6)
		param->number_of_times_eat = ft_atoi_pos(argv[5]);
	else
		param->number_of_times_eat = 0;
	return (1);
}

void	ft_print_status(t_philo *philo, enum e_state state)
{
	long	time;

	philo->state = state;
	time = ft_gettime();
	if (state == take_fork && !philo->end)
		printf("%ld %d has taken a fork\n", time, philo->number);
	if (state == eating && !philo->end)
		printf("%ld %d is eating\n", time, philo->number);
	if (state == sleeping && !philo->end)
		printf("%ld %d is sleeping\n", time, philo->number);
	if (state == thinking && !philo->end)
		printf("%ld %d thinking\n", time, philo->number);
	if (state == died)
		printf("%ld %d died\n", time, philo->number);
	if (state == meal_finished && !philo->end)
	{
		philo->last_eat = time;
		philo->time_to_eat++;
	}
}

void	ft_philo_pick_fork(t_philo *philo)
{
	if (philo->number % 2)
	{
		ft_print_status(philo, take_fork);
		pthread_mutex_lock(philo->fork_left);
		ft_print_status(philo, take_fork);
		pthread_mutex_lock(philo->fork_right);
	}
	else
	{
		ft_print_status(philo, take_fork);
		pthread_mutex_lock(philo->fork_right);
		ft_print_status(philo, take_fork);
		pthread_mutex_lock(philo->fork_left);
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
