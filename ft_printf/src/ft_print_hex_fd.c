/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/07 10:51:59 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_fd(t_format *format)
{
	unsigned long	ul;

	ul = (unsigned int) va_arg(*format->ap, unsigned int);
	format->len = ft_len_ltox(ul);
	ft_margin_left(format->margin - format->len, format);
	ft_zero_padded(format->margin - format->len, format);
	if (format->sharp && ul != 0)
	{
		if (format->c == 'X')
			write(format->fd, "0X", 2);
		else
			write(format->fd, "0x", 2);
		format->len += 2;
	}
	if (format->c == 'X')
		ft_uitox_up_fd(ul, format->fd);
	else
		ft_uitox_fd(ul, format->fd);
	ft_margin_right(format->margin - format->len, format);
}
