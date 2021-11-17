/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:34:26 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/16 14:34:26 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/**
 * @brief write to file destination fd a char
 * 
 * @param c 
 * @param fd 
 */
void	ft_putchar_fd(char c, int fd)
{	
	write(fd, &c, 1);
}
