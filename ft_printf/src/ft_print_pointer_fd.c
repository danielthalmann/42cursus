/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 08:39:15 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer_fd(t_format *format)
{
	unsigned long	ul;

	ul = (unsigned long) va_arg(*format->ap, void *);
	format->len = ft_len_ltox(ul) + 2;
	ft_margin_left(format->margin - format->len, format);
	write(format->fd, "0x", 2);
	ft_ltox_fd(ul, format->fd);
	ft_margin_right(format->margin - format->len, format);
}
