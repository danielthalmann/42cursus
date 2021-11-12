/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:34:06 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 22:18:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
