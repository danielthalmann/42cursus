/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:22:07 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/09 10:22:06 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "ft_transmission.h"
#include "ft_print.h"
#include "ft_strdup.h"

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

void	ft_exit(t_transmission *t)
{
	free(t->str);
	exit(0);
}

void	ft_transmit(t_transmission *t)
{
	if (t->str[t->idx])
	{
		if (t->octet < 8)
		{
			if (t->str[t->idx] & (0x1 << t->octet))
				t->send = SIGUSR2;
			else
				t->send = SIGUSR1;
			t->octet++;
			if (kill(t->pid, t->send) == -1)
				ft_error("Sending error\n");
		}
		else
		{
			ft_clean_transmission(t);
			t->idx++;
			ft_transmit(t);
		}
	}
	else
		ft_exit(t);
}	

void	sig_handler(__attribute__((unused)) int signum)
{
	t_transmission	*t;

	t = ft_get_transmission();
	ft_transmit(t);
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
	t->str = ft_strdup(argv[2]);
	signal(SIGUSR1, sig_handler);
	ft_transmit(t);
	while (1)
		pause();
	return (0);
}
