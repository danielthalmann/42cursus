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
 * @brief locates the	first occurrence of the	null-termi-
     nated string little in the	string big, where not more than	
	 len characters
     are searched
 * 
 * @param str 
 * @param to_find 
 * @param len 
 * @return char* 
 */
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!*to_find)
		return ((char *)str);
	l = ft_strlen(to_find);
	while (*str && i++ < len)
	{
		if (ft_strncmp(str, to_find, l) == 0)
			return ((char *)str);
		str++;
	}
	return (0);
}
