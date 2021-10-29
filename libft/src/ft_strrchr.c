/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:41:11 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/18 13:41:11 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  returns a pointer to the last occurrence of the character c 
 *         in the string s
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*r;

	r = 0;
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			r = str;
		str++;
	}
	if (c == 0)
		return (str);
	return (r);
}
