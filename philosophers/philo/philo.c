/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:34:44 by dthalman          #+#    #+#             */
/*   Updated: 2022/02/02 11:45:27 by dthalman         ###   ########.fr       */
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
