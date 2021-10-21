/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:27:58 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/21 21:27:58 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief Applique la fonction ’f’ à chaque caractère de la chaine de caractères 
 * passée en argument pour créer une nouvelle chaine de caractères 
 * (avec malloc(3)) résultant des applications successives de ’f’.
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*r;

	r = malloc((ft_strlen(s) + 1) * sizeof(char));
	i = -1;
	while (s[++i])
		r[i] = (*f)(i, s[i]);
	r[i] = 0;
	return (r);
}
