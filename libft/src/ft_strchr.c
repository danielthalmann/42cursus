/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:15:14 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/17 12:15:14 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief returns a pointer to the first occurrence of the character c 
 * 		  in the string s.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str && str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}
