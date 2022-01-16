/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:37:29 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/14 15:17:23 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

/**
 * @brief Résoud le tri avec la liste qui a été préparé
 * 
 * @param lists 
 */
void	ft_push_swap_resolv(t_swap *lists)
{
	if (ft_is_list_sorted(lists->a.list))
		return ;
	if (lists->a.length < 3)
	{
		if (ft_a_gt_b(lists->a.list, lists->a.list->next))
			ft_exec(sa, lists);
		return ;
	}
	if (lists->a.length == 3)
		return (ft_push_swap_resolv_3(lists));
	if (lists->a.length < 6)
		return (ft_push_swap_resolv_5(lists));
	ft_push_swap_resolv_100(lists);
}

/**
 * @brief résoud une liste qui contient uniquement 3 entrées
 * 
 * @param lists 
 */
void	ft_push_swap_resolv_3(t_swap *lists)
{
	if (ft_a_gt_b(lists->a.list, lists->a.list->next))
	{
		if (ft_a_gt_b(lists->a.list, lists->a.list->next->next))
		{
			ft_exec(ra, lists);
			if (ft_a_gt_b(lists->a.list, lists->a.list->next))
				ft_exec(sa, lists);
		}
		else
			ft_exec(sa, lists);
	}
	else
	{
		if (ft_a_gt_b(lists->a.list->next, lists->a.list->next->next))
		{
			ft_exec(rra, lists);
			if (ft_a_gt_b(lists->a.list, lists->a.list->next))
				ft_exec(sa, lists);
		}
	}
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
		//j = ft_get_index_of(lists->b.list, ft_get_value(lists->a.list));
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

/**
 * @brief résoud une liste qui contient jsuqu'à 5 entrées
 * 
 * @param lists 
 */
void	ft_push_swap_resolv_5(t_swap *lists)
{
	ft_exec(pb, lists);
	ft_exec(pb, lists);
	if (lists->a.length == 3)
		ft_push_swap_resolv_3(lists);
	else
	{
		if (ft_a_gt_b(lists->b.list, lists->b.list->next)
			&& ft_a_gt_b(lists->b.list, lists->b.list->next))
			ft_exec(ss, lists);
		else if (ft_a_gt_b(lists->a.list, lists->a.list->next))
			ft_exec(sa, lists);
	}
	if (ft_a_lt_b(lists->b.list, lists->b.list->next))
		ft_exec(sb, lists);
	while (lists->b.length)
		ft_push_swap_resolv_b_to_sort_a(lists);
	ft_push_swap_resolv_5_final(lists);
}

/**
 * @brief résoud une liste jusqu'à 100 entrées
 * 
 * @param lists 
 */
void	ft_push_swap_resolv_200(t_swap *lists)
{
	t_uint	i;
	t_uint	size;

	size = lists->a.length;
	ft_list_indexing(lists->a.list, lists->a.length);
	i = 0;
	while (i++ < size / 2)
	{
		// recherche le prochain en dessus
		while (ft_get_index(lists->a.list) <= size / 2)	{
			if (lists->a.length > 1)
				if (ft_a_gt_b(lists->a.list, lists->a.list->next))
					ft_exec(sa, lists);	
			ft_exec(ra, lists);
		}
		ft_push_swap_resolv_a_to_b(lists);
	}
	while (lists->b.length)
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
		ft_exec(pa, lists);
	}
	i = 0;
	while (i++ < size / 2)
	{
		ft_exec(rra, lists);
		ft_push_swap_resolv_a_to_b(lists);
	}
	while (lists->b.length)
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
		ft_exec(pa, lists);
	}
}

/**
 * @brief résoud une liste jusqu'à 500 entrées
 * 
 * @param lists 
 */

void	ft_push_swap_resolv_500(t_swap *lists)
{
	t_uint	i;

	while (lists->a.length > 1)
	{
		if (ft_a_lt_b(lists->a.list, lists->a.list->next))
			ft_exec(pb, lists);
		else
		{
			if (lists->b.length > 1
				&& ft_a_lt_b(lists->b.list, lists->b.list->next))
				ft_exec(ss, lists);
			else
				ft_exec(sa, lists);
			ft_exec(pb, lists);
		}
	}
	while (lists->b.length > 1)
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
		ft_exec(pa, lists);
	}
	ft_exec(pa, lists);
}

long	ft_search_next_index_p(t_list2 *l, t_uint min, t_uint max)
{
	t_uint	index;
	t_uint	final_index;

	index = 0;
	while (l)
	{
		final_index = ft_get_index(l);
		if (final_index >= min && final_index <= max)
			return (index);
		l = l->previous;
		index++;
	}
	return (-1);	
}

long	ft_search_next_index(t_list2 *l, t_uint min, t_uint max)
{
	t_uint	index;
	t_uint	final_index;

	index = 0;
	while (l)
	{
		final_index = ft_get_index(l);
		if (final_index >= min && final_index <= max)
			return (index);
		l = l->next;
		index++;
	}
	return (-1);	
}

void	ft_push_b_region(t_swap *lists, t_uint size, t_uint split, t_uint index)
{
	long	j;

	j = 0;
	if (index != split - 1)
		j = ft_search_next_index_p(lists->a.end, ((size / split) * index), ((size / split) * (index + 1)));
	else
		j = ft_search_next_index(lists->a.list, ((size / split) * index), ((size / split) * (index + 1)));
	while (j > -1)
	{
		if (index != split - 1)
			j++;
		if (j != lists->a.length)
		{
			while (j)
			{
				if (index != split - 1)
					ft_exec(rra, lists);
				else
					ft_exec(ra, lists);
				j--;
			}
		}
		ft_push_swap_resolv_a_to_b(lists);
		if (index != split - 1)
			j = ft_search_next_index_p(lists->a.end, ((size / split) * index), ((size / split) * (index + 1)));
		else
			j = ft_search_next_index(lists->a.list, ((size / split) * index), ((size / split) * (index + 1)));
	}
}

/**
 * @brief résoud une liste jusqu'à 500 entrées
 * 
 * @param lists 
 */
void	ft_push_swap_resolv_100(t_swap *lists)
{
	t_uint	j;
	t_uint	size;
	t_uint	cute;

	size = lists->a.length;
	cute = 5;
	ft_list_indexing(lists->a.list, lists->a.length);
	j = cute;
	while (j > 0)
	{
		j--;
		ft_push_b_region(lists, size, cute, j);
		while (lists->b.length)
			ft_push_swap_resolv_sort_b_to_a(lists);
	}
	ft_exec(pa, lists);
}
