/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:28:45 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/18 11:28:45 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

int	ft_is_list_valid(t_swap *lists)
{
	t_uint	i;
	t_list2	*l;
	t_list2	*p;

	l = lists->a;
	i = -1;
	while (l && ++i < ((lists->a_length + 1) / 2))
	{
		p = l->previous;
		while (p)
		{
			if (((t_number *)l->content)->n == ((t_number *)p->content)->n)
				return (0);
			p = p->previous;
		}
		p = l->next;
		while (p)
		{
			if (((t_number *)l->content)->n == ((t_number *)p->content)->n)
				return (0);
			p = p->next;
		}
		l = l->next;
	}
	return (1);
}
