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
#include<stdio.h>
/**
 * @brief écrit dans la console le contenu de la chaine format et substituant
 * les valeurs %... par le contenu des variables supplémentaires passé en 
 * paramètre de la fonction.
 * 
 * @param format chaine de caractère à formater
 * @param ... variables supplémentaires à introduire dans le formatage
 */
void	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		c;

	va_start(ap, format);
	while (*format)
	{
		c = *format;
		if (c == '%')
			format = ft_treat_percent(&ap, (char *)format, 1);
		else
			write(1, &c, 1);
		format++;
	}
	va_end(ap);
}

/**
 * @brief Initialise les valeurs de la structure t_format qui
 * contient les modificateurs à appliquer sur le formatage
 * 
 * @param ap pointeur sur les arguments de la fonction
 * @param fd 
 * @param format 
 */
void	ft_clear_type_format(va_list *ap, int fd, t_format *format)
{
	format->margin = 0;
	format->mod = 0;
	format->c = 0;
	format->align_left = 0;
	format->ap = ap;
	format->fd = fd;
	format->space_sign = 0;
	format->plus_sign = 0;
	format->zero_fill = 0;
}

/**
 * @brief Traite un modificateur et modifie la structure t_format
 * pour identifier les actions à entreprendre
 * 
 * @param c 
 * @param format 
 */
void	ft_read_modifier(char c, t_format *format)
{
	if (c == '-')
		format->align_left = 1;
	if (c == ' ')
		format->space_sign = 1;
	if (c == '+')
		format->plus_sign = 1;
	if (c == '0')
		format->zero_fill = 1;
}

/**
 * @brief Effectue le remplacement des % dans la chaine de formatage
 * 
 * @param ap pointeur sur les arguments de la fonction
 * @param s_format 
 * @param fd 
 * @return char* 
 */
char	*ft_treat_percent(va_list *ap, char *s_format, int fd)
{
	t_format	f;
	char		*s;

	s = s_format;
	s_format++;
	ft_clear_type_format(ap, fd, &f);
	while (ft_strchr("-0.# +", *s_format))
		ft_read_modifier(*(s_format++), &f);
	while (*s_format >= '0' && *s_format <= '9')
		f.margin = (f.margin * 10) + (*(s_format++) - '0');
	if (ft_strchr("cspdiuxX%", *s_format))
	{
		f.c = *s_format;
		ft_print_format_fd(&f);
	}
	else
	{
		write(fd, "%", 1);
		return (s);
	}
	return (s_format);
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
	int		len;

	c = (char) va_arg(*format->ap, int);
	len = format->margin - 1;
	ft_format_space(1, len, format);
	write(format->fd, &c, 1);
	ft_format_space(0, len, format);
}

void	ft_format_space(int left, int len, t_format *format)
{
	if (left)
	{
		if (!format->align_left)
			while (len-- > 0)
				write(format->fd, " ", 1);
	}
	else
	{
		if (format->align_left)
			while (len-- > 0)
				write(format->fd, " ", 1);
	}
}

void	ft_print_string_fd(t_format *format)
{
	char	*s;
	int		len;

	s = (char *) va_arg(*format->ap, char *);
	if (!s)
		s = "(null)";
	len = format->margin - ft_strlen(s);
	ft_format_space(1, len, format);
	while (*s)
		write(format->fd, s++, 1);
	ft_format_space(0, len, format);
}

void	ft_print_pointer_fd(t_format *format)
{
	unsigned long	ul;

	ul = (unsigned long) va_arg(*format->ap, void *);
	if (!ul)
		write(format->fd, "(nil)", 5);
	else
	{
		write(format->fd, "0x", 2);
		ft_ltox_fd(ul, format->fd);
	}
}

void	ft_print_integer_fd(t_format *format)
{
	int	i;
	int	len;

	i = (int) va_arg(*format->ap, int);
	len = format->margin - ft_len_itoa(i);
	if (format->align_left && (format->space_sign || format->plus_sign))
		len--;
	ft_format_space(1, len, format);
	if ((format->space_sign || format->plus_sign) && i > -1 && len < 1)
	{
		if (format->plus_sign)
			write(format->fd, "+", 1);
		else
			write(format->fd, " ", 1);
	}
	ft_itoa_fd(i, format->fd);
	ft_format_space(0, len, format);
}

void	ft_print_unsigned_dec_fd(t_format *format)
{
	unsigned int	ui;

	ui = (unsigned int) va_arg(*format->ap, unsigned int);
	ft_uitoa_fd(ui, format->fd);
}

void	ft_print_hex_fd(t_format *format)
{
	unsigned int	ui;

	ui = (unsigned int) va_arg(*format->ap, unsigned int);
	write(format->fd, "0x", 2);
	ft_ltox_fd(ui, format->fd);
}
