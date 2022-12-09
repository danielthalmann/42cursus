/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:37:29 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/14 15:18:05 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

void	ft_push_swap_resolv_b_to_sort_a(t_swap *lists)
{
	t_uint	i;

	if (lists->a.length > 0)
	{		
		i = ft_get_index_of(lists->a.list, ft_get_value(lists->b.list));
		if (lists->a.length > i * 2)
		{
			while (i--)
				ft_exec(ra, lists);
		}
		else
		{
			i = lists->a.length - i;
			while (i--)
				ft_exec(rra, lists);
		}
	}	
	ft_exec(pa, lists);
}

void	ft_push_swap_resolv_a_to_b(t_swap *lists)
{
	t_uint	j;

	if (lists->b.length > 0)
	{
		j = ft_get_smallindex_of(lists->b.list, ft_get_value(lists->a.list));
		if (lists->b.length > j * 2)
		{
			while (j--)
				ft_exec(rb, lists);
		}
		else
		{
			j = lists->b.length - j;
			while (j--)
				ft_exec(rrb, lists);
		}
	}
	ft_exec(pb, lists);
}

void	ft_push_swap_resolv_sort_b_to_a(t_swap *lists)
{
	t_uint	i;

	if (lists->b.length > 0)
	{
		i = ft_next_height(lists->b.list);
		if (lists->b.length > i * 2)
		{
			while (i--)
				ft_exec(rb, lists);
		}
		else
		{
			i = lists->b.length - i;
			while (i--)
				ft_exec(rrb, lists);
		}
	}
	ft_exec(pa, lists);
}

void	ft_push_swap_resolv_5_final(t_swap *lists)
{
	t_uint	i;

	i = ft_next_low(lists->a.list);
	if (lists->a.length > i * 2)
	{
		while (i--)
			ft_exec(ra, lists);
	}
	else
	{
		i = lists->a.length - i;
		while (i--)
			ft_exec(rra, lists);
	}
}
