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
	lists.a = 0;
	lists.b = 0;
	lists.a_end = 0;
	lists.b_end = 0;
	lists.length = --argc;
	lists.a_end = ft_load_list(&lists.a, lists.length, ++argv);
	ft_printf("nombre d'objet dans la liste : %d\n", lists.length);
	ft_resolv(&lists);
	ft_lst2clear(&(lists.a), free);
	ft_lst2clear(&(lists.b), free);
	return (0);
}

t_list2	*ft_load_list(t_list2 **list, unsigned int l, char **v)
{
	unsigned int	i;
	t_number		*n;
	t_list2			*lst;

	i = -1;
	lst = 0;
	while (++i < l)
	{
		n = malloc(sizeof(n));
		if (!n)
		{
			ft_lst2clear(list, free);
			return (0);
		}
		n->s = v[i];
		n->n = ft_atoi(v[i]);
		lst = ft_lst2new(n);
		ft_lst2add_back(list, lst);
	}
	return (lst);
}

void ft_resolv(t_swap *lists)
{
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
	/*
	ft_swap_a(lists);
	ft_print_swap(lists);
	ft_push_a(lists);
	ft_print_swap(lists);
	ft_push_a(lists);
	ft_print_swap(lists);
	ft_push_b(lists);
	ft_print_swap(lists);
	ft_push_b(lists);
	ft_print_swap(lists);
	ft_swap_b(lists);
	ft_print_swap(lists);
	ft_push_b(lists);
	ft_print_swap(lists);
	*/
}