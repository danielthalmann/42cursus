/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:49:38 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/23 20:49:38 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief Alloue (avec malloc(3)) et retourne une chaine de caractères issue 
 *        de la chaine ’s’. Cette nouvelle chaine commence à l’index ’start’ 
 *        et a pour taille maximale ’len’.
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*st;
	char	*en;
	char	*ret;
	int		l;
	size_t	i;

	st = (char *)s;
	i = 0;
	while (*st && i < start)
	{
		st++;
		i++;
	}
	en = st;
	i = 0;
	while (*en && i < len)
	{
		en++;
		i++;
	}
	l = (en - st);
	ret = malloc((l + 1) * sizeof(char));
	if (ret)
		ft_strlcpy(ret, st, (l + 1));
	return (ret);
}
