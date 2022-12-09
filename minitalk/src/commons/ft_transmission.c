/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transmission.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:00:03 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/07 11:02:02 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_transmission.h"

t_transmission	*ft_get_transmission(void)
{
	static t_transmission	t;

	return (&t);
}

void	ft_clean_transmission(t_transmission *t)
{
	t->octet = 0;
	t->send = 0;
}
