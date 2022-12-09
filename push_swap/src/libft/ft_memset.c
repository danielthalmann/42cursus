/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:59:10 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/16 11:59:10 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief fills the first n bytes of the memory area pointed 
 * 		  to by s with the constant byte c.
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return void* 
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = -1;
	while (++i < n)
		((char *)s)[i] = c;
	return (s);
}
