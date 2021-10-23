/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:25:49 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/23 18:25:49 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief Alloue (avec malloc(3)) et retourne une copie dela chaine ’s1’, 
 * 		  sans les caractères spécifiés dans ’set’ au début et à la fin de 
 *        la chaine decaractères.
 * 
 * @param s1 
 * @param set 
 * @return char* 
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	int		length;
	char	*start;
	char	*end;
	char	*ret;

	start = (char *)s1;
	while (*start && ft_strrchr(set, *(start)))
		start++;
	end = start;
	while (*end)
		end++;
	end--;
	while (*end && ft_strrchr(set, *end))
		end--;
	length = (end - start) + 1;
	ret = (char *)malloc((length + 1) * sizeof(char));
	ft_strlcpy(ret, start, (length + 1));
	return (ret);
}
