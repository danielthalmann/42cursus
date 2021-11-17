/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/17 07:55:36 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	ft_itoa_fd2(int nb, int fd, int len, t_format *format)
{
	if (nb < 0)
	{
		write(fd, "-", 1);
		if (format->decimal_point)
			len++;
		ft_zero_padded(len, format);
		ft_uitoa_fd(-nb, fd);
	}
	else
	{
		ft_zero_padded(len, format);
		ft_uitoa_fd(nb, fd);
	}
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
