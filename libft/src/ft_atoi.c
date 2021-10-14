/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:51:42 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/14 21:51:42 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief check if the value is one of space character '\t', '\n', '\v','\f', '\r', ' '
 * 
 * @param c char value
 * @return int This function returns non-zero value if c is a space, else it returns 0. 
 */
int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

/**
 * @brief check if the value is a character sign '+' or '-'
 * 
 * @param c char value
 * @return int This function returns non-zero value if c is a sign, else it returns 0. 
 */
int	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

/**
 * @brief Converts the string pointed to, by the argument str to an integer (type int).
 * 
 * @param str 
 * @return unsigned int 
 */
unsigned int	ft_convnum(char *str)
{
	unsigned int	value;
	int				first;

	first = 1;
	value = 0;
	while (*str && ft_isdigit(*str))
	{
		if (first)
		{
			value = *str - '0';
			first = 0;
		}
		else
		{
			value = value * 10;
			value = value + (*str - '0');
		}
		str++;
	}
	return (value);
}


/**
 * @brief Converts the string pointed to, by the argument str to an integer (type int).
 * 
 * @param str string pointer
 * @return int the value converted of the the string
 */
int	ft_atoi(char *str)
{
	unsigned int	value;
	int				sign;

	if (*str == 0)
		return (0);
	value = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	while (*str && ft_issign(*str))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	value = ft_convnum(str);
	return (sign * value);
}
