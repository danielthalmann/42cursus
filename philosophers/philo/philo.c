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

void	ft_philo_factory(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->param->nb_of_philosophers);
	while (i < table->param->nb_of_philosophers)
	{	
		table->philos[i].number = i;
		pthread_create (&(table->philos[i].thread), NULL, &ft_philo_work,
			&(table->philos[i]));
		pthread_mutex_init(&(table->philos[i].fork_left), NULL);
		table->philos[i].state = sleeping;
		table->philos[i].time_to_eat = 0;
		table->philos[i].table = table;
		if (i > 0)
			table->philos[i - 1].fork_right = &(table->philos[i].fork_left);
		i++;
	}
	table->philos[table->param->nb_of_philosophers - 1].fork_right = &(table->philos[0].fork_left);
}

void	ft_philo_dispose(t_table *table)
{
	free(table->philos);
}

void	ft_philo_wait_end(t_table *table)
{
	int	i;

	i = table->param->nb_of_philosophers;
	while (i--)
		pthread_join (table->philos[i].thread, NULL);
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
	if (param->nb_of_philosophers < 2)
	{
		printf("The number og philosopher is not enought\n\n");
		return (0);
	}
	param->time_to_die = ft_atoi_pos(argv[2]);
	param->time_to_eat = ft_atoi_pos(argv[3]);
	param->time_to_sleep = ft_atoi_pos(argv[4]);
	if (argc == 6)
		param->number_of_times_eat = ft_atoi_pos(argv[5]);
	else
		param->number_of_times_eat = 0;
	return (1);
}

void *ft_philo_work(void *arg)
{
	t_philo	*philo;
	int		right_philo;

	philo = (t_philo *)arg;
	printf("start_routine %d\n", philo->number);
	while (philo->table->param->number_of_times_eat == 0 ||
		philo->time_to_eat < philo->table->param->number_of_times_eat)
	{
		printf("lock left fork %d\n", philo->number);
		pthread_mutex_lock(&philo->fork_left);
		right_philo = philo->number + 1 % philo->table->param->nb_of_philosophers;
		printf("lock right fork %d\n", right_philo);
		pthread_mutex_lock(philo->fork_right);
		printf("eat %d\n", right_philo);
		usleep(philo->table->param->time_to_eat * 1000);
		printf("release left fork %d\n", philo->number);
		pthread_mutex_unlock(philo->fork_right);
		printf("release right fork %d\n", philo->number);
		pthread_mutex_unlock(&philo->fork_left);
	}
	return (arg);
}