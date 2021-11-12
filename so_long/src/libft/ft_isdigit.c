/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:00:04 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/14 22:00:04 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief checks if the passed character is a decimal digit character.
 * 
 * @param c This is the character to be checked.
 * @return int This function returns non-zero value if c is a digit, 
 * 		   else it returns 0.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
