/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:34:56 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/30 09:53:30 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

enum e_state
{
	take_fork,
	eating,
	meal_finished,
	sleeping,
	thinking,
	died
};
typedef	struct s_parameter
{
	int	nb_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_eat;
;
}	t_parameter;
struct s_table;
typedef	struct s_philo
{
	int				number;
	pthread_t		thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	enum e_state	state;
	int				time_to_eat;
	struct s_table	*table;
	long			last_eat;
	int				end;
}	t_philo;
typedef	struct s_table
{
	int				place;
	int				start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	t_parameter		*param;
}	t_table;
int		load_parameter(t_parameter *param, int argc, char **argv);
void	*ft_philo_work(void *p);
int		ft_atoi_pos(const char *nptr);
void	ft_philo_factory(t_table *table);
void	ft_philo_wait_end(t_table *table);
void	ft_philo_dispose(t_table *table);
void	ft_print_status(t_philo *philo, enum e_state state);

#endif
