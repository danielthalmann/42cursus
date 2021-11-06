/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 09:32:58 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_fd(t_format *format)
{
	unsigned int	ui;

	ui = (unsigned int) va_arg(*format->ap, unsigned int);
	format->len = ft_len_ltox(ui);
	ft_margin_left(format->margin - format->len, format);
	ft_zero_padded(format->margin - format->len, format);
	if(format->sharp)
	{
		write(format->fd, "0x", 2);
		format->len += 2;
	}
	if (format->c == 'X')
		ft_ltox_up_fd(ui, format->fd);
	else
		ft_ltox_fd(ui, format->fd);
	ft_margin_right(format->margin - format->len, format);
}
