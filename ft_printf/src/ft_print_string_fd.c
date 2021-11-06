/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 08:39:21 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string_fd(t_format *format)
{
	char	*s;
	int		len;
	int		length;

	s = (char *) va_arg(*format->ap, char *);
	if (!s)
		s = "(null)";
	len = format->margin - ft_strlen(s);
	ft_margin_left(len, format);
	if (format->decimal_point)
	{
		length = format->margin;
		while (*s && (length--))
			ft_repeat_char(1, *(s++), format);
	}
	else
	{
		while (*s)
			ft_repeat_char(1, *(s++), format);
	}
	ft_margin_right(len, format);
}
