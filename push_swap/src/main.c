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
#include "swap.h"
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
		ft_print_swap(&lists);
	}
	else
		ft_fprintf(2, "Error\n");
	ft_free_swap_list(&lists);
	return (0);
}

void ft_push_swap_resolv_3(t_swap *lists)
{
	if (ft_a_gt_b(lists->a, lists->a->next))
	{
		if (ft_a_gt_b(lists->a, lists->a->next->next))
		{
			ft_exec(CMD_RA, lists);
			if (ft_a_gt_b(lists->a, lists->a->next))
				ft_exec(CMD_SA, lists);
		}
		else
			ft_exec(CMD_SA, lists);
	}
	else
	{
		if (ft_a_gt_b(lists->a->next, lists->a->next->next))
		{
			ft_exec(CMD_RRA, lists);
			if (ft_a_gt_b(lists->a, lists->a->next))
				ft_exec(CMD_SA, lists);
		}
	}
}

void ft_push_swap_resolv(t_swap *lists)
{
	t_uint	i;
	t_uint	j;
	t_uint length;

	if (lists->a_length < 3)
	{
		if (ft_a_gt_b(lists->a, lists->a->next))
			ft_exec(CMD_SA, lists);
		return ;
	}
	if (lists->a_length == 3)
	{
		ft_push_swap_resolv_3(lists);
		return ;
	}
	if (lists->a_length < 6)
	{
		if (ft_a_gt_b(lists->a, lists->a->next))
			ft_exec(CMD_SA, lists);
		ft_exec(CMD_RA, lists);
		if (ft_a_gt_b(lists->a, lists->a->next))
			ft_exec(CMD_SA, lists);
		return ;
	}
	j = 0;
	i = 0;
	length = lists->a_length;
	while(i < length)
	{
		j = i;
		while(j < length - i)
		{
			if (ft_a_gt_b(lists->a, lists->a->next))
				ft_exec(CMD_SA, lists);
			ft_exec(CMD_RA, lists);
			j++;
		}
		i++;
	}
}
