/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:35:43 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/15 12:35:43 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief checks whether c is a 7-bit unsigned char value that fits 
 * 		  into the ASCII character set.
 * 
 * @param c character
 * @return int return non-zero value if is a alphabetic character
 */
int	ft_isascii(int c)
{
	return (c > -1 && c < 128);
}
