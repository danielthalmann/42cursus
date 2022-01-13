/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:37:29 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/13 18:32:30 by dthalman         ###   ########.fr       */
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

/**
 * @brief résoud une liste qui contient jsuqu'à 5 entrées
 * 
 * @param lists 
 */
void	ft_push_swap_resolv_5(t_swap *lists)
{
	t_uint	i;

	ft_print_swap(lists);
	i = lists->a.length - 1 - ft_next_height(lists->a.list);
	ft_printf("index %d \n", i);
	if (i > lists->a.length / 2)
	{
		i = lists->a.length - i;
		ft_printf("index %d \n", i);
		while (i--)
		{
			ft_exec(ra, lists);
			ft_print_swap(lists);
			sleep(1);
		}

	}
	else
	{
		while (i--)
		{
			ft_exec(rra, lists);
			ft_print_swap(lists);
			sleep(1);
		}

	}

}

/**
 * @brief résoud une liste jusqu'à 100 entrées
 * 
 * @param lists 
 */
void	ft_push_swap_resolv_100(t_swap *lists)
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
