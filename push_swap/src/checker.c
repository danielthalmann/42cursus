/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:28:45 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/09 12:04:18 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

int	ft_is_list_valid(t_swap *lists)
{
	t_uint	i;
	t_list2	*l;
	t_list2	*p;

	l = lists->a.list;
	i = -1;
	while (l && ++i < ((lists->a.length + 1) / 2))
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
