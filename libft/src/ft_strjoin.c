/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:22:10 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/17 23:22:10 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include "libft.h"

/**
 * @brief Alloue (avec malloc()) et retourne une nouvelle chaine, 
 * 	 	  résultat de la concaténation de s1 et s2.6
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	char	*r;
	int		i;

	length = ft_strlen(s1);
	length += ft_strlen(s2);
	r = malloc((length + 1) * sizeof(char));
	if (!r)
		return (0);
	i = 0;
	while (s1)
		r[i++] = *(s1++);
	while (s1)
		r[i++] = *(s1++);
	r[i] = 0;
	return (r);
}