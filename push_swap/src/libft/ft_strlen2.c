/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:48:29 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/11 23:52:33 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compte la longueur de la chaine se terminant par '\0' ou 
 * par l'un des caractères contenu dans la chaine eos.
 * le caractère contenu dans eos est compté dans le retour
 * 
 * @param s 
 * @param eos 
 * @return int len of string
 */
size_t	ft_strlen2(char *s, char *eos)
{
	unsigned int	c;
	int				i;
	int				p;

	c = 0;
	p = 0;
	while (*s && !p)
	{
		i = 0;
		while (eos[i])
		{
			if (eos[i] == *s)
			{
				p = 1;
				break ;
			}
			i++;
		}
		c++;
		s++;
	}
	return (c);
}
