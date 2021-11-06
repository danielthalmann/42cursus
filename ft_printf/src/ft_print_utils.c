/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:20:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/06 09:42:29 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	format->decimal_point = 0;
	format->len = 0;
	format->sharp = 0;
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
	if (c == '.')
		format->decimal_point = 1;
	if (c == '#')
		format->sharp = 1;
}
