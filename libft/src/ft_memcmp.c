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
	unsigned char	*sa;
	unsigned char	*sb;

	if (!s1)
		return (1);
	if (!s2)
		return (-1);
	sa = (unsigned char *)s1;
	sb = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*sa != *sb)
			return ((unsigned char)*sa - (unsigned char)*sb);
		sa++;
		sb++;
	}
	return (0);
}
