/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:22:07 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/05 10:04:22 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "ft_signum.h"

t_transmission	*ft_get_transmission()
{
	static t_transmission	t;

	return (&t);
}

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

void	ft_transmit(int process, char *str)
{
	int	octet;

	while (*str)
	{
		octet = 0;
		while (octet < 8)
		{
			if (*str & (0x1 << octet))
				kill(process, SIGUSR2);
			else
				kill(process, SIGUSR1);
			octet++;
			pause();
		}
		str++;
	}
}

void	ft_print(char *str)
{
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

void sig_handler(int signum)
{
	t_transmission	*t;

	(void) signum;
	t = ft_get_transmission();
	if (*(t->str))
	{
		usleep(100000);
	ft_print("sig_handler argument\n");
		if (t->octet < 8)
		{
			if (*(t->str) & (0x1 << t->octet))
				kill(t->pid, SIGUSR2);
			else
				kill(t->pid, SIGUSR1);
			t->octet++;
		}
		else
		{
			t->octet = 0;
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
	raise(SIGUSR1);
	return (0);
}
