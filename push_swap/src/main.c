/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 07:43:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/14 14:05:32 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list2.h"
#include "push_swap.h"
#include "libft.h"
#include "main.h"

int	main(int argc, char **argv)
{
	t_swap	lists;

	if (argc < 2)
	{
		ft_fprintf(2, "Error\n");
		return (1);
	}
	ft_load_swap_list(&lists, ++argv, argc - 1);
	if (ft_is_list_valid(&lists))
	{
		// ft_print_swap(&lists);
		ft_push_swap_resolv(&lists);
		//ft_print_swap(&lists);
	}
	else
		ft_fprintf(2, "Error\n");
	ft_free_swap_list(&lists);
	return (0);
}

void ft_push_swap_resolv_3(t_swap *lists)
{
	if (ft_a_gt_b(lists->a.list, lists->a.list->next))
	{
		if (ft_a_gt_b(lists->a.list, lists->a.list->next->next))
		{
			ft_exec(CMD_RA, lists);
			if (ft_a_gt_b(lists->a.list, lists->a.list->next))
				ft_exec(CMD_SA, lists);
		}
		else
			ft_exec(CMD_SA, lists);
	}
	else
	{
		if (ft_a_gt_b(lists->a.list->next, lists->a.list->next->next))
		{
			ft_exec(CMD_RRA, lists);
			if (ft_a_gt_b(lists->a.list, lists->a.list->next))
				ft_exec(CMD_SA, lists);
		}
	}
}

/**
 * @brief retourne l'index du plus au nombre
 * 
 * @param c 
 * @return t_uint 
 */
t_uint	ft_next_height(t_list2 *c)
{
	t_uint idx_height;
	t_uint idx_curr;
	t_list2 *l_height;

	idx_height = 0;
	idx_curr = 0;
	l_height = c;
	c = c->next;
	while(c)
	{
		idx_curr++;
		if (ft_a_lt_b(l_height, c))
		{
			idx_height = idx_curr;
			l_height = c;
		}
		c = c->next;
	}
	return (idx_height);
}

/**
 * @brief retourne le plus grand nombre
 * 
 * @param c 
 * @return t_uint 
 */
t_uint	ft_height_value(t_list2 *c)
{
	t_list2 *l_height;

	l_height = c;
	c = c->next;
	while(c)
	{
		if (ft_a_lt_b(l_height, c))
			l_height = c;
		c = c->next;
	}
	return (l_height);
}

/**
 * @brief retourne le plus petit nombre
 * 
 * @param c 
 * @return t_uint 
 */
t_uint	ft_low_value(t_list2 *c)
{
	t_list2 *l_low;

	l_low = c;
	c = c->next;
	while(c)
	{
		if (ft_a_lt_b(c, l_low))
			l_low = c;
		c = c->next;
	}
	return (l_low);
}

void ft_push_swap_resolv(t_swap *lists)
{
	t_uint	i;

	if (lists->a.length < 3)
	{
		if (ft_a_gt_b(lists->a.list, lists->a.list->next))
			ft_exec(CMD_SA, lists);
		return ;
	}
	if (lists->a.length == 3)
	{
		ft_push_swap_resolv_3(lists);
		return ;
	}

	while(lists->a.length > 1)
	{
		if (ft_a_lt_b(lists->a.list, lists->a.list->next))
			ft_exec(CMD_PB, lists);
		else
		{
			if (lists->b.length > 1 && ft_a_lt_b(lists->b.list, lists->b.list->next))
				ft_exec(CMD_SS, lists);
			else
				ft_exec(CMD_SA, lists);
			ft_exec(CMD_PB, lists);
		}
	}
	while(lists->b.length > 1)
	{
		i = ft_next_height(lists->b.list);
		if (lists->b.length > i * 2)
		{
			while(i--)
				ft_exec(CMD_RB, lists);
		}
		else
		{
			i = lists->b.length - i;
			while(i--)
				ft_exec(CMD_RRB, lists);
		}
		ft_exec(CMD_PA, lists);
	}
	ft_exec(CMD_PA, lists);
}
