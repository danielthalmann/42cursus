/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:55:31 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/15 14:55:31 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief checks for any printable character including space.
 * 
 * @param c 
 * @return int 
 */
int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
