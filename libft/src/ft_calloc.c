/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:26:08 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/15 10:26:08 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "stdio.h"

/**
 * @brief allocates the requested memory and returns a pointer to it.
 * 
 * @param nmemb This is the number of elements to be allocated.
 * @param size This is the size of elements in byte
 * @return void* 
 */
void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void	*r;
	int		length;

	length = nmemb * size;
	r = malloc(length);
	ft_bzero(r, length);
	return (r);
}
