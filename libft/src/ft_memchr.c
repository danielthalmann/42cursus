/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:48:23 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/15 22:48:23 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Searches in num bytes of the block of memory pointed by ptr for the 
 * 		  first occurrence of value
 * 
 * @param s block of memory pointed
 * @param c value to be locate
 * @param n length of memory block in byte
 * @return void* 
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = -1;
	while (++i < n)
	{
		if (((char *)s)[i] == (unsigned char)c)
			return ((void *)&((char *)s)[i]);
	}
	return (0);
}
