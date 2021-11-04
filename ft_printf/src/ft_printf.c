/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:38:56 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/05 00:38:56 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		c;

	va_start(ap, format);
	while (*format)
	{
		c = *format;
		format++;
		if (c == '%')
			format = ft_treat_type(&ap, (char *)format, 1);
		else
			write(1, &c, 1);
	}
	va_end(ap);
}

char	*ft_treat_type(va_list *ap, char *format, int fd)
{
	t_format	f;

	if (*format)
	{
		f.mod = 0;
		if (ft_strchr("-0.# +", *format))
			f.mod = *(format++);
		f.margin = 0;
		while ((*format >= '0' && *format <= '9'))
			f.margin = (f.margin * 10) + (*(format++) - '0');
		if (ft_strchr("cspdiuxX%", *format))
		{
			f.c = *format;
			f.ap = ap;
			f.fd = fd;
			ft_print_format_fd(&f);
			format++;
		}
		else
			write(fd, "%", 1);
	}
	return (format);
}

void	ft_print_format_fd(t_format *format)
{
	if (format->c == 'c')
		ft_print_char_fd(format);
	else if (format->c == 's')
		ft_print_string_fd(format);
	else if (format->c == 'p')
		ft_print_pointer_fd(format);
	else if (format->c == 'i' || format->c == 'd')
		ft_print_integer_fd(format);
	else if (format->c == 'u')
		ft_print_unsigned_dec_fd(format);
	else if (format->c == 'x' || format->c == 'X')
		ft_print_hex_fd(format);
	else if (format->c == '%')
		write(format->fd, "%", 1);
}

void	ft_print_char_fd(t_format *format)
{
	char	c;

	c = (char) va_arg(*format->ap, int);
	write(format->fd, &c, 1);
}

void	ft_print_string_fd(t_format *format)
{
	char	*s;
	int		len;

	s = (char *) va_arg(*format->ap, char *);
	len = format->margin - ft_strlen(s);
	if (format->mod != '-')
		while (len-- > 0)
			write(format->fd, " ", 1);
	while (*s)
		write(format->fd, s++, 1);
	if (format->mod == '-')
		while (len-- > 0)
			write(format->fd, " ", 1);
}

void	ft_print_pointer_fd(t_format *format)
{
	unsigned long	ul;

	ul = (unsigned long) va_arg(*format->ap, void *);
	(void) ul;
	write(format->fd, "?", 1);
}

void	ft_print_integer_fd(t_format *format)
{
	int	i;

	i = (int) va_arg(*format->ap, int);
	ft_itoa_fd(i, format->fd);
}

void	ft_print_unsigned_dec_fd(t_format *format)
{
	unsigned int	ui;

	ui = (unsigned int) va_arg(*format->ap, unsigned int);
	(void) ui;
	write(format->fd, "?", 1);
}

void	ft_print_hex_fd(t_format *format)
{
	unsigned int	ui;

	ui = (unsigned int) va_arg(*format->ap, unsigned int);
	(void) ui;
	write(format->fd, "?", 1);
}
