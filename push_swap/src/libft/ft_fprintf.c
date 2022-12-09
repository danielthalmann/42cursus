/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:38:56 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 13:50:42 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief écrit dans fd le contenu de la chaine format et substituant
 * les valeurs %... par le contenu des variables supplémentaires passé en 
 * paramètre de la fonction.
 * 
 * @param fd identifiant d'un file descriptor
 * @param format chaine de caractère à formater
 * @param ... variables supplémentaires à introduire dans le formatage
 */
int	ft_fprintf(int fd, const char *format, ...)
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
			format = ft_treat_percent(&ap, (char *)format, &f, fd);
			len += f.len;
		}
		else
		{
			write(fd, &c, 1);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
