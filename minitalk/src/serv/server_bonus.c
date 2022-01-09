/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:19:00 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/09 10:35:07 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_signum.h"
#include "ft_bzero.h"
#include "ft_print.h"
#include "ft_transmission.h"

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	t_transmission	*t;

	(void) context;
	t = ft_get_transmission();
	t->send = signum;
	t->pid = info->si_pid;
}

void	ft_print_message(t_transmission *t)
{
	static char		c;

	t = ft_get_transmission();
	if (t->send == SIGUSR2)
		c |= (0x1 << t->octet);
	t->octet++;
	if (t->octet == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		c = 0;
		t->octet = 0;
	}
}

void	ft_error(char *str)
{
	ft_print(str);
	exit(1);
}

int	main(void)
{
	struct sigaction	act;
	int					process;
	t_transmission		*t;

	t = ft_get_transmission();
	ft_bzero(&act, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &ft_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		ft_error("error sigaction\n");
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		ft_error("error sigaction\n");
	process = getpid();
	ft_print("PSID : ");
	ft_print_nb(process);
	ft_print("\n");
	pause();
	while (1)
	{
		ft_print_message(t);
		usleep(20);
		kill(t->pid, t->send);
		pause();
	}
}
