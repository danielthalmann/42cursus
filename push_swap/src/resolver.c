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
	if (lists->a.length < 101)
		return (ft_push_swap_resolv_100(lists));
	ft_push_swap_resolv_500(lists);
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

void	ft_push_swap_resolv_100(t_swap *lists)
{
	t_uint	j;
	t_uint	size;
	t_uint	cute;

	size = lists->a.length;
	cute = 6;
	ft_list_indexing(lists->a.list, lists->a.length);
	j = 0;
	while (j < cute)
		ft_push_b_region(lists, size, cute, j++);
	while (lists->b.length)
		ft_push_swap_resolv_sort_b_to_a(lists);
	ft_exec(pa, lists);
}

/**
 * @brief résoud une liste jusqu'à 500 entrées
 * 
 * @param lists 
 */
void	ft_push_swap_resolv_500(t_swap *lists)
{
	t_uint	j;
	t_uint	size;
	t_uint	cute;

	size = lists->a.length;
	cute = 13;
	ft_list_indexing(lists->a.list, lists->a.length);
	j = cute;
	while (j--)
		ft_push_b_region(lists, size, cute, j);
	while (lists->b.length)
		ft_push_swap_resolv_sort_b_to_a(lists);
	ft_exec(pa, lists);
}
