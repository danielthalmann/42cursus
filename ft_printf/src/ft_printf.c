/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:38:56 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 08:39:45 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief écrit dans la console le contenu de la chaine format et substituant
 * les valeurs %... par le contenu des variables supplémentaires passé en 
 * paramètre de la fonction.
 * 
 * @param format chaine de caractère à formater
 * @param ... variables supplémentaires à introduire dans le formatage
 */
int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		c;
	int			len;
	t_format	f;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		c = *format;
		if (c == '%')
		{
			format = ft_treat_percent(&ap, (char *)format, &f, 1);
			len += f.len;
		}
		else
		{
			write(1, &c, 1);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}

/**
 * @brief Effectue le remplacement des % dans la chaine de formatage
 * 
 * @param ap pointeur sur les arguments de la fonction
 * @param s_format 
 * @param fd 
 * @return char* 
 */
char	*ft_treat_percent(va_list *ap, char *s_format, t_format	*f, int fd)
{
	char		*s;

	s = s_format;
	s_format++;
	ft_clear_type_format(ap, fd, f);
	while (ft_strchr("-0.# +", *s_format))
		ft_read_modifier(*(s_format++), f);
	while (*s_format >= '0' && *s_format <= '9')
		f->margin = (f->margin * 10) + (*(s_format++) - '0');
	if (ft_strchr("cspdiuxX%", *s_format))
	{
		f->c = *s_format;
		ft_print_format_fd(f);
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
	{
		write(format->fd, "%", 1);
		format->len++;
	}
}
