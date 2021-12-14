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
	t_swap			lists;

	if (argc < 2)
	{
		ft_fprintf(2, "Error\n");
		return (1);
	}
	ft_load_swap_list(&lists, --argc, ++argv);
	// ft_print_swap(&lists);
	ft_push_swap_resolv(&lists);
	// ft_print_swap(&lists);
	//ft_push_swap_test(&lists);
	ft_free_swap_list(&lists);
	return (0);
}

void ft_push_swap_resolv(t_swap *lists)
{
	t_uint	i;
	t_uint	j;
	t_uint length;

	if (lists->a_length < 3)
	{
		if (ft_a_gt_b(lists->a, lists->a->next))
			ft_exec(CMD_RA, lists);
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

void ft_push_swap_test(t_swap *lists)
{
	ft_print_swap(lists);
	ft_reverse_rotate_a(lists);
	ft_print_swap(lists);
	ft_reverse_rotate_a(lists);
	ft_print_swap(lists);
	ft_reverse_rotate_a(lists);
	ft_push_a(lists);
	ft_push_a(lists);
	ft_push_a(lists);
	ft_push_a(lists);
	ft_print_swap(lists);
	ft_push_a(lists);
	ft_print_swap(lists);
	ft_rotate_b(lists);
	ft_print_swap(lists);
	ft_rotate_b(lists);
	ft_print_swap(lists);
}