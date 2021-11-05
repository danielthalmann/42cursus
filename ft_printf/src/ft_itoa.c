/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/15 15:20:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief return the string length necessary to write number
 * 
 * @param nb 
 * @return int 
 */
int	ft_len_itoa(int nb)
{
	int	length;

	length = 0;
	if (nb <= 0)
		length++;
	while (nb)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

/**
 * @brief write a string of the number passed in parameter to file
 * descriptor fd
 * 
 * @param nb 
 * @return char* 
 */
void	ft_itoa_fd(int nb, int fd)
{
	if (nb < 0)
	{
		write(fd, "-", 1);
		ft_uitoa_fd(-nb, fd);
	}
	else
		ft_uitoa_fd(nb, fd);
}

void	ft_uitoa_fd(unsigned int nb, int fd)
{
	char	c;

	if (nb < 10)
	{
		c = '0' + nb;
		write(fd, &c, 1);
	}
	else
	{
		ft_itoa_fd(nb / 10, fd);
		ft_itoa_fd(nb % 10, fd);
	}		
}

void	ft_ltoa_fd(long nb, int fd)
{
	char	c;

	if (nb < 10)
	{
		c = '0' + nb;
		write(fd, &c, 1);
	}
	else
	{
		ft_ltoa_fd(nb / (long)10, fd);
		ft_ltoa_fd(nb % (long)10, fd);
	}
}

void	ft_ltox_fd(long nb, int fd)
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
