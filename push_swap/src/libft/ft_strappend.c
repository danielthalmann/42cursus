/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:31:00 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/11 22:55:08 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

/**
 * @brief Concatène deux chaines de caractère et libère la mémoire de la 
 * chaine s1
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_str_append(char *s1, char *s2)
{
	char	*o;
	char	*so;
	char	*s;

	o = malloc((ft_strlen2(s1, "") + ft_strlen2(s2, "") + 1) * sizeof(char));
	if (!o)
		return (0);
	so = o;
	s = s1;
	while (*s)
		*(so++) = *(s++);
	while (*s2)
		*(so++) = *(s2++);
	*so = 0;
	free(s1);
	return (o);
}
