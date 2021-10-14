/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:49:09 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/14 22:49:09 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief erases the data in the n bytes of the memory starting at the location pointed
 * 
 * @param s pointer of data
 * @param n size in byte to erase
 */
void	ft_bzero(void *s, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
	}
}
