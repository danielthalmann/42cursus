
#include "libft.h"


void	clear_array_ch(char *c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		c[i] = 0;
		i++;
	}
}

void	print_c(char *c, int l)
{
	int	i;

	if (c[0] == '-')
	{
		write(1, c, 1);
		i = l - 1;
		while (i > 0)
		{
			write(1, &c[i], 1);
			i--;
		}
	}
	else
	{
		i = l - 1;
		while (i >= 0)
		{
			write(1, &c[i], 1);
			i--;
		}
	}
}

int	exception(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	char	c[12];
	int		i;

	if (exception(nb) == 1)
	{
		return ;
	}
	clear_array_ch(c, 12);
	i = 0;
	if (nb < 0)
	{
		c[i] = '-';
		i++;
		nb = -nb;
	}
	while (nb > 0 && i < 12)
	{
		c[i] = '0' + (nb % 10);
		nb = nb / 10;
		i++;
	}
	print_c(c, i);
}