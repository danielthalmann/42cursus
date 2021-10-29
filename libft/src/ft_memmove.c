/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:57:58 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/16 11:57:58 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief copies  n bytes from memory area src to memory area dest.
 * 	      The memory areas maybe overlap
 * 
 * @param dest 
 * @param src 
 * @param n 
 * @return void* 
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (dest < src)
	{
		i = -1;
		while (++i < n)
			((char *)dest)[i] = ((char *)src)[i];
	}
	if (src < dest)
	{
		i = n;
		while (i-- > 0)
			((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}
