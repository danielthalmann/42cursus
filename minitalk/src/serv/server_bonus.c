/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:19:00 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/07 12:02:25 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_signum.h"
#include "ft_bzero.h"
#include "ft_print.h"

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static int	octet;
	static char	c;

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
	usleep(100);
	kill(info->si_pid, signum);
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
		pause();
}
