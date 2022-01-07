/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:22:07 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/07 17:08:40 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "ft_signum.h"
#include "ft_transmission.h"
#include "ft_print.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	value;

	if (*nptr == 0)
		return (0);
	value = 0;
	while (*nptr && !(*nptr >= '0' && *nptr <= '9'))
		nptr++;
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		value *= 10;
		value += *nptr - '0';
		nptr++;
	}
	return (value);
}

void	ft_acknoledge(t_transmission *t)
{
	if (t->send != 0)
	{
		if (t->send != t->ack)
		{
			ft_print("Error aknowledge\n");
			exit(1);
		}	
	}
}

void	sig_handler(int signum)
{
	t_transmission	*t;

	t = ft_get_transmission();
	t->ack = signum;
}

void	ft_transmit(t_transmission *t)
{
	while (*(t->str))
	{
		if (t->octet < 8)
		{
			if (*(t->str) & (0x1 << t->octet))
				t->send = SIGUSR2;
			else
				t->send = SIGUSR1;
			usleep(50);
			kill(t->pid, t->send);
			pause();
			ft_acknoledge(t);
			t->octet++;
		}
		else
		{
			ft_clean_transmission(t);
			t->str++;
		}
	}
}	

int	main(int argc, char **argv)
{
	t_transmission	*t;

	if (argc != 3)
	{
		ft_print("invalid argument\n");
		return (1);
	}
	t = ft_get_transmission();
	t->pid = ft_atoi(argv[1]);
	t->str = argv[2];
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_transmit(t);
	return (0);
}
