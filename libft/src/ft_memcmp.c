/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:51:10 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/15 23:51:10 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief compares the first n bytes (each interpreted as unsigned char) 
 *        of the memory areas s1 and s2
 * 
 * @param s1 memory block pointer
 * @param s2 memory block pointer 
 * @param n lenght bytes
 * @return int obtain a non-zero value if the block is different
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = -1;
	while (++i < n && ((char *)s1)[i] && ((char *)s2)[i])
		if (((char *)s1)[i] != ((char *)s2)[i])
			break ;
	return (((char *)s1)[i] - ((char *)s2)[i]);
}