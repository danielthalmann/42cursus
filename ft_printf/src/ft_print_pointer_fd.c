/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/15 15:20:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer_fd(t_format *format)
{
	unsigned long	ul;

	ul = (unsigned long) va_arg(*format->ap, void *);
	if (!ul)
	{
		format->len = 5;
		ft_format_space(1, format->margin - 5, format);
		write(format->fd, "(nil)", 5);
		ft_format_space(0, format->margin - 5, format);
	}
	else
	{
		format->len = ft_len_ltox(ul) + 2;
		ft_format_space(1, format->margin - format->len, format);
		write(format->fd, "0x", 2);
		ft_ltox_fd(ul, format->fd);
		ft_format_space(0, format->margin - format->len, format);
	}
}
