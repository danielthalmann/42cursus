/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:20:46 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/11 22:53:17 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief déplace le contenu de la chaine de from dans to
 * pour une longueur de chaine donnée par len
 * from est avancé de 1 au début
 * 
 * @param to 
 * @param from 
 * @param len longueur à copier
 */
void	ft_strmov(char *to, char *from, int len)
{
	int	i;

	from++;
	len = ft_strlen2(from, "");
	i = 0;
	while (i < len)
	{
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
}
