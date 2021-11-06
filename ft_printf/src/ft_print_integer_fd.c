/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 08:39:09 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_integer_fd(t_format *format)
{
	int	i;
	int	len;

	i = (int) va_arg(*format->ap, int);
	format->len = ft_len_itoa(i);
	len = format->margin - format->len;
	if (format->align_left && (format->space_sign || format->plus_sign))
		len--;
	ft_margin_left(len, format);
	if ((format->space_sign || format->plus_sign) && i > -1 && len < 1)
	{
		if (format->plus_sign)
			write(format->fd, "+", 1);
		else
			write(format->fd, " ", 1);
		format->len++;
		len++;
	}
	ft_itoa_fd2(i, format->fd, len, format);
	ft_margin_right(len, format);
}
