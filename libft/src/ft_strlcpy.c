/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:55:13 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/19 22:55:13 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

/**
 * @brief copies up to size - 1 characters from the NUL-terminated string 
 * 	      src to dst, NUL-terminating the result.
 * 
 * @param dst 
 * @param src 
 * @param size 
 * @return size_t 
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
{
	char	*ret;

	ret = (char *)dst;
	while (*src != 0 && size > 1)
	{	
		*(dst++) = *(src++);
		size--;
	}
	while (size > 1)
	{
		*(dst++) = 0;
		size--;
	}
	*dst = 0;
	return (ret);
}
