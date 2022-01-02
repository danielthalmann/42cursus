
#include <signal.h>
#include <unistd.h>
#include "signum.h"

void ft_handler (int signum)
{
	static int	octet;
	static char	c;

	if (signum == SIGUSR1)
		c |= (0x0 << octet);
	if (signum == SIGUSR2)
		c |= (0x1 << octet);
	octet++;
	if(octet == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		c = 0;
		octet = 0;
	}
}

void ft_print(char *str)
{
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

void ft_print_nb(int value)
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

int main (void)
{
	struct sigaction new_action;
	struct sigaction old_action;
	int	process;
	/* Set up the structure to specify the new action. */
	sigemptyset (&new_action.sa_mask);
	new_action.sa_flags = 0;
	new_action.sa_handler = &ft_handler;
	sigaction(SIGUSR1, &new_action, &old_action);
	sigaction(SIGUSR2, &new_action, &old_action);
	process = getpid();
	ft_print("process id : ");
	ft_print_nb(process);
	ft_print("\n");
	while (1)
		pause();
}