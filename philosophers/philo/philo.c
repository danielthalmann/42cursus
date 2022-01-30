/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:34:44 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/30 13:05:15 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_parameter	param;
	t_table		table;
	int			i;

	if (!load_parameter(&param, argc, argv))
		return (0);
	table.param = &param;
	ft_philo_factory(&table);
	ft_philo_wait_end(&table);
	ft_philo_dispose(&table);

}

long	ft_gettime()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	ft_philo_factory(t_table *table)
{
	int	i;
	long	time;

	table->philos = malloc(sizeof(t_philo) * table->param->nb_of_philosophers);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->param->nb_of_philosophers);
	i = 0;
	while (i < table->param->nb_of_philosophers)
	{	
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < table->param->nb_of_philosophers)
	{	
		table->philos[i].number = i;
		pthread_create (&(table->philos[i].thread), NULL, &ft_philo_work,
			&(table->philos[i]));
		table->philos[i].fork_left = &table->forks[i];
		table->philos[i].fork_right = &table->forks[(i + 1) % table->param->nb_of_philosophers];
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
}

int	ft_all_died(t_philo *philos, int len)
{
	while (len--)
	{
		if(!philos[len].end)
			return (0);
	}
	return (1);
}

void	ft_philo_wait_end(t_table *table)
{
	int		i;
	long	time;
	int		end;

	end = 0;
	while (!end)
	{			
		time = ft_gettime();
		i = table->param->nb_of_philosophers;
		while (i--)
		{
			if (!table->philos[i].end &&
				table->param->number_of_times_eat > 0 &&
				table->philos[i].time_to_eat >= table->param->number_of_times_eat)
			{
				table->philos[i].end = 1;
				ft_print_status(&table->philos[i], died);
				pthread_detach(table->philos[i].thread);
			}
			if (!table->philos[i].end && table->philos[i].state != eating && time - table->philos[i].last_eat > table->param->time_to_die * 1000)
			{
				printf("%ld %d died time %ld %d\n",time, i, time - table->philos[i].last_eat, table->param->time_to_die * 1000);
				ft_print_status(&table->philos[i], died);
				table->philos[i].end = 1;
				pthread_detach(table->philos[i].thread);
				end = 1;
			}
			if (ft_all_died(table->philos, table->param->nb_of_philosophers))
				end = 1;
		}
		usleep(10000);
	}
	i = table->param->nb_of_philosophers;
	while (i--)
	{
		table->philos[i].end = 1;
		pthread_join (table->philos[i].thread, NULL);
	}
}

/**
 * @brief Charge les paramètres de la commande
 * 
 * @param param 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	load_parameter(t_parameter *param, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("The number of arguments is invalid.\n\n");
		printf("type : %s [nb_of_philosophers] [time_to_die] ", argv[0]);
		printf("[time_to_eat] [time_to_sleep]");
		printf("\n optional  : [number_of_times_eat]\n\n");
		return (0);
	}
	param->nb_of_philosophers = ft_atoi_pos(argv[1]);
	/*
	if (param->nb_of_philosophers < 2)
	{
		printf("The number og philosopher is not enought\n\n");
		return (0);
	}
	*/
	param->time_to_die = ft_atoi_pos(argv[2]);
	param->time_to_eat = ft_atoi_pos(argv[3]);
	param->time_to_sleep = ft_atoi_pos(argv[4]);
	if (argc == 6)
		param->number_of_times_eat = ft_atoi_pos(argv[5]);
	else
		param->number_of_times_eat = 0;
	return (1);
}

void ft_print_status(t_philo *philo, enum e_state state)
{
	long	time;

	philo->state = state;
	time = ft_gettime();
	if (state == take_fork && !philo->end)
		printf("%ld %d has taken a fork\n", time, philo->number);
	if (state == eating && !philo->end)
	{
		//philo->last_eat = time;
		printf("%ld %d is eating\n", time, philo->number);
	}
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

void *ft_philo_work(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	ft_print_status(philo, thinking);
	while (!philo->end)
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

		ft_print_status(philo, eating);
		usleep(philo->table->param->time_to_eat * 1000);
		ft_print_status(philo, meal_finished);
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		ft_print_status(philo, sleeping);
		usleep(philo->table->param->time_to_sleep * 1000);
		ft_print_status(philo, thinking);
	}
	return (arg);
}