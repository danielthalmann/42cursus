/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_dec_fd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 08:39:28 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned_dec_fd(t_format *format)
{
	unsigned int	ui;

	ui = (unsigned int) va_arg(*format->ap, unsigned int);
	format->len = ft_len_itoa(ui);
	ft_margin_left(format->margin - format->len, format);
	ft_zero_padded(format->margin - format->len, format);
	ft_uitoa_fd(ui, format->fd);
	ft_margin_right(format->margin - format->len, format);
}
