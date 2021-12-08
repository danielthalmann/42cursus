/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 07:43:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/04 18:56:09 by dthalman         ###   ########.fr       */
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
	ft_resolv(&lists);
	ft_free_swap_list(&lists);
	return (0);
}

void ft_resolv(t_swap *lists)
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