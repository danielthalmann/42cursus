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
#include "main.h"
#include "swap.h"

int	main(int argc, char **argv)
{
	t_list			*list_a;
	t_list			*list_b;
	unsigned int	n;

	if (argc < 2)
	{
		ft_fprintf(2, "Error\n");
		return (1);
	}
	list_a = 0;
	list_b = 0;
	n = ft_load_list(&list_a, --argc, ++argv);
	ft_printf("nombre d'objet dans la liste : %d\n", n);
	ft_resolv(&list_a, &list_b, n);
	ft_lstclear(&list_a, free);
	ft_lstclear(&list_b, free);
	return (0);
}

unsigned int	ft_load_list(t_list	**list, unsigned int l, char **v)
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

void ft_resolv(t_list **list_a, t_list **list_b, int n)
{
	
}