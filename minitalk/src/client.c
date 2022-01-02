
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "signum.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	value;

	if (*nptr == 0)
		return (0);
	value = 0;
	while (*nptr && (*nptr < '0' || *nptr > '9'))
		nptr++;
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		value *= 10;
		value = *nptr - '0';
		nptr++;
	}
	return (value);
}

void ft_transmit(int process, char *str)
{
	int	octet;

	while (*str)
	{
		octet = 0;
		while (octet < 8)
		{
			if (*str & (0x1 << octet))
				kill(process, SIGUSR1);
			else
				kill(process, SIGUSR1);
			octet++;
		}
		kill(process, SIGUSR1);
		str++;
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

int main (int argc, char **argv)
{
	int	process;

	if (argc != 3)
	{
		ft_print("invalid argument\n");
		return (1);
	}
	process = ft_atoi(argv[1]);
	ft_transmit(process, argv[2]);
	return (0);
}
