/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:14:29 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/18 17:14:29 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief locates the first occurrence of the null-terminated 
 * string little in the	string big, where not more than	len characters
 * are searched
 * if the len of to_find is big as len of search str, the return is null
 * 
 * @param str 
 * @param to_find 
 * @param len 
 * @return char* 
 */
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	l;

	if (!*to_find)
		return ((char *)str);
	l = ft_strlen(to_find);
	while (*str && len)
	{
		if (ft_strncmp(str, to_find, l) == 0 && len >= l)
			return ((char *)str);
		str++;
		len--;
	}
	return (0);
}
