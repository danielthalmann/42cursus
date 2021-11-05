/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/15 15:20:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_ltox(unsigned long nb)
{
	int	length;

	length = 0;
	if (nb <= 0)
		length++;
	while (nb)
	{
		nb /= 16;
		length++;
	}
	return (length);
}

void	ft_ltox_fd(unsigned long nb, int fd)
{
	char	*s;

	if (nb < 16)
	{
		s = "0123456789abcdef";
		s = s + nb;
		write(fd, s, 1);
	}
	else
	{
		ft_ltox_fd(nb / (long)16, fd);
		ft_ltox_fd(nb % (long)16, fd);
	}
}

void	ft_ltox_up_fd(unsigned long nb, int fd)
{
	char	*s;

	if (nb < 16)
	{
		s = "0123456789ABCDEF";
		s = s + nb;
		write(fd, s, 1);
	}
	else
	{
		ft_ltox_up_fd(nb / (long)16, fd);
		ft_ltox_up_fd(nb % (long)16, fd);
	}
}
