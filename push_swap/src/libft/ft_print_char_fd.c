/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 22:18:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_char_fd(t_format *format)
{
	char	c;
	int		len;

	c = (char) va_arg(*format->ap, int);
	format->len++;
	len = format->margin - 1;
	ft_margin_left(len, format);
	write(format->fd, &c, 1);
	ft_margin_right(len, format);
}
