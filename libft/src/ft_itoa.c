/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/15 15:20:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief return the string length necessary to write number
 * 
 * @param nb 
 * @return int 
 */
int	ft_len_itoa(int nb)
{
	int	length;

	length = 0;
	if (nb < 0)
	{
		length++;
	}
	while (nb)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

/**
 * @brief obtain a string of the number passed in parameter
 * 
 * @param nb 
 * @return char* 
 */
char	*ft_itoa(int nb)
{
	char	*s;
	int		length;
	int		i;
	int		v;

	length = ft_len_itoa(nb);
	s = ft_calloc(length + 1, sizeof(char));
	if (!s)
		return (0);
	i = length;
	s[i] = 0;
	i--;
	if (nb < 0)
		s[0] = '-';
	while (nb && i > -1)
	{
		v = (nb % 10);
		if (v < 0)
			v = -v;
		s[i] = '0' + v;
		nb = nb / 10;
		i--;
	}
	return (s);
}
