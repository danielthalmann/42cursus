/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 08:39:33 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero_padded(int len, t_format *format)
{
	if (!(format->zero_fill || format->decimal_point))
		return ;
	ft_repeat_char(len, '0', format);
}

void	ft_repeat_char(int len, char c, t_format *format)
{
	while (len-- > 0)
	{
		write(format->fd, &c, 1);
		format->len++;
	}
}

void	ft_margin_left(int len, t_format *format)
{
	if (format->zero_fill || format->decimal_point)
		return ;
	if (!format->align_left)
		ft_repeat_char(len, ' ', format);
}

void	ft_margin_right(int len, t_format *format)
{
	if (format->zero_fill || format->decimal_point)
		return ;
	if (format->align_left)
		ft_repeat_char(len, ' ', format);
}
