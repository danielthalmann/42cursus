/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 00:13:54 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/16 00:13:54 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief copies n bytes from memory area src to memory area dest
 * 
 * @param dest memory destination
 * @param src memory source
 * @param n 
 * @return void* 
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = -1;
	while (++i < n)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}
