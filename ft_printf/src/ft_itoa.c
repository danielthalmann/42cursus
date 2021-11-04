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
	char			c;
	unsigned int	v;

	if (nb < 0)
	{
		write(fd, "-", 1);
		v = -nb;
	}
	else
		v = nb;
	if (v < 10)
	{
		c = '0' + v;
		write(fd, &c, 1);
	}
	else
	{
		ft_itoa_fd(v / 10, fd);
		ft_itoa_fd(v % 10, fd);
	}		
}
