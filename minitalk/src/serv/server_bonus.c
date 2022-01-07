/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:19:00 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/07 17:12:37 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
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

void	ft_send(void)
{
	static char		c;
	t_transmission	*t;

	t = ft_get_transmission();
	if (t->send == SIGUSR1)
		c |= (0x0 << t->octet);
	if (t->send == SIGUSR2)
		c |= (0x1 << t->octet);
	t->octet++;
	if (t->octet == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		c = 0;
		t->octet = 0;
	}
	usleep(50);
	kill(t->pid, t->send);
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
	ft_print("PSID : ");
	ft_print_nb(process);
	ft_print("\n");
	while (1)
	{
		pause();
		ft_send();
	}
}
