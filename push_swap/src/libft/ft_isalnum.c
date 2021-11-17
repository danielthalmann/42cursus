/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:25:11 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/15 11:25:11 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief checks for an alphanumeric character; it is equivalent 
 *        to (ft_isalpha(c) || ft_isdigit(c)).
 * 
 * @param c 
 * @return int return non-zero value if is a alphabetic or numeric character
 */
int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
