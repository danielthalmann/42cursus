/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:34:44 by dthalman          #+#    #+#             */
/*   Updated: 2022/02/09 11:09:54 by dthalman         ###   ########.fr       */
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
	table.start_time = ft_gettime();
	if(ft_print_mutex_factory(&table))
	{
		if (ft_philo_factory(&table))
			ft_philo_wait_end(&table);
		else
			ft_philo_end(&table);
		ft_philo_dispose(&table);		
	}
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

	if (!table->philos)
		return ;
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
	long	time;

	end = 0;
	while (!end)
	{			
		i = table->param->nb_of_philos;
		time = (ft_gettime() - table->start_time);
		while (i--)
		{
			if (!table->philos[i].end
				&& time	- table->philos[i].last_eat - 8
				> table->param->time_to_die)
			{
				table->philos[i].end = 1;
				ft_apply_status(&table->philos[i], died);
				pthread_detach(table->philos[i].thread);
				end = 1;
			}
			if (ft_all_died(table->philos, table->param->nb_of_philos))
				end = 1;
		}
		usleep(1000);
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
		printf("\noptional  : [number_of_times_eat]\n\n");
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
