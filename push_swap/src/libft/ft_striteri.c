/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:08:15 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/17 16:08:15 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applique la fonction f à chaque caractère de lachaîne de caractères
 *  	  transmise comme argument, et en passant son index comme premier 
 * 		  argument. 
 * 		  Chaque caractère est transmis par adresse à f pour êtremodifié si 
 * 		  nécessaire.
 * 
 * @param s 
 * @param f 
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = -1;
	while (s && s[++i])
		(*f)(i, &s[i]);
}
