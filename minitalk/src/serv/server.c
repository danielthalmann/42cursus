/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:19:00 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/05 09:19:00 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_signum.h"
#include "ft_bzero.h"

void	ft_print(char *str);

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static int	octet;
	static char	c;

	(void) info;
	(void) context;
	if (signum == SIGUSR1)
		c |= (0x0 << octet);
	if (signum == SIGUSR2)
		c |= (0x1 << octet);
	octet++;
	if (octet == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		c = 0;
		octet = 0;
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

void	ft_print_nb(int value)
{
	char	c;

	if (value < 0)
	{
		ft_print("-");
		ft_print_nb(-value);
	}
	else if (value < 10)
	{
		c = '0' + value;
		write(STDOUT_FILENO, &c, 1);
	}
	else
	{
		ft_print_nb(value / 10);
		ft_print_nb(value % 10);
	}
}

int	main(void)
{
	struct sigaction	act;
	int					process;

	ft_bzero(&act, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &ft_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		ft_print("error sigaction\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &act, NULL) == -1)
	{
		ft_print("error sigaction\n");
		return (1);
	}
	process = getpid();
	ft_print("process id : ");
	ft_print_nb(process);
	ft_print("\n");
	while (1)
		pause();
}
