/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:21:37 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/19 21:21:37 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  appends the NUL-terminated string src to the end of dst. 
 *         It will append at most size - strlen(dst) - 1 bytes, 
 *         NUL-terminating the result
 * 
 * @param dst 
 * @param src 
 * @param size 
 * @return size_t return the total length of the string they tried 
 * 		   to create.
 * 		   that means the initial length of dst plus the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	len;
	char	*s;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	len = src_len + dst_len;
	s = (char *)src;
	if (dst_len <= size)
	{
		while (*s && (dst_len + 1) < size)
			dst[dst_len++] = *(s++);
		dst[dst_len] = 0;
		return (len);
	}
	return (src_len + size);
}
