/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/15 15:20:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string_fd(t_format *format)
{
	char	*s;
	int		len;

	s = (char *) va_arg(*format->ap, char *);
	if (!s)
		s = "(null)";
	format->len = ft_strlen(s);
	len = format->margin - format->len;
	ft_format_space(1, len, format);
	while (*s)
		write(format->fd, s++, 1);
	ft_format_space(0, len, format);
}
