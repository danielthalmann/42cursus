/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:28:15 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/07 11:32:25 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *str)
{
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

void	ft_print_nb(int value)
{
	char	c;

	if (value < 0)
	{
		ft_print("-");
		ft_print_nb(-value);
	}
	else if (value < 10)
	{
		c = '0' + value;
		write(STDOUT_FILENO, &c, 1);
	}
	else
	{
		ft_print_nb(value / 10);
		ft_print_nb(value % 10);
	}
}
