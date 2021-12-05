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
	unsigned int	n;

	if (argc < 2)
	{
		ft_fprintf(2, "Error\n");
		return (1);
	}
	lists.a = 0;
	lists.b = 0;
	n = ft_load_list(&lists.a, --argc, ++argv);
	ft_printf("nombre d'objet dans la liste : %d\n", n);
	ft_resolv(&lists, n);
	ft_lstclear(&(lists.a), free);
	ft_lstclear(&(lists.b), free);
	return (0);
}

unsigned int	ft_load_list(t_list2 **list, unsigned int l, char **v)
{
	unsigned int	i;
	t_number		*n;

	i = -1;
	while (++i < l)
	{
		n = malloc(sizeof(n));
		if (!n)
		{
			ft_lstclear(list, free);
			return (0);
		}
		n->s = v[i];
		n->n = ft_atoi(v[i]);
		ft_lstadd_back(list, ft_lstnew(n));
	}
	return (i);
}

void ft_resolv(t_swap *lists, int n)
{
	(void) n;
	ft_swap_a(lists);
	ft_print_swap(lists);
	ft_swap_pa(lists);
	ft_print_swap(lists);
	ft_swap_pb(lists);
	ft_print_swap(lists);
}