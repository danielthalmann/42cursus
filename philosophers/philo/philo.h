/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:34:56 by dthalman          #+#    #+#             */
/*   Updated: 2022/02/09 10:44:22 by dthalman         ###   ########.fr       */
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
typedef struct s_parameter
{
	int	nb_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_eat;
}	t_parameter;
struct	s_table;
typedef struct s_philo
{
	int				number;
	pthread_t		thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	enum e_state	state;
	int				time_to_eat;
	struct s_table	*table;
	long			last_eat;
	long			last_chstatus;
	int				end;
}	t_philo;
typedef struct s_table
{
	int				place;
	long			start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	t_parameter		*param;
}	t_table;
int		ft_load_parameter(t_parameter *param, int argc, char **argv);
void	*ft_philo_work(void *p);
int		ft_atoi_pos(const char *nptr);
long	ft_gettime(void);
int		ft_all_died(t_philo *philos, int len);
int		ft_print_mutex_factory(t_table *table);
int		ft_fork_factory(t_table *table);
int		ft_philo_factory(t_table *table);
void	ft_philo_wait_end(t_table *table);
void	ft_philo_end(t_table *table);
void	ft_philo_dispose(t_table *table);
void	ft_print_status(t_philo *philo, long time);
void	ft_apply_status(t_philo *philo, enum e_state state);
void	ft_philo_pick_fork(t_philo *philo);
#endif
