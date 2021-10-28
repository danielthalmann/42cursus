/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:51:52 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/17 14:51:52 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include "libft.h"

char	*ft_strcpy(char *dest, const char *src);

/**
 * @brief returns a pointer to a new string which is a duplicate 
 * 		  of the string s.
 * 
 * @param s 
 * @return char* 
 */
char	*ft_strdup(const char *s)
{
	int		length;
	char	*dest;

	length = ft_strlen(s);
	dest = (malloc((length + 1) * sizeof (char)));
	if (dest)
		ft_strlcpy(dest, s, (length + 1));
	return (dest);
}
