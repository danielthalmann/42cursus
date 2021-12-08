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
	ft_push_swap_test(&lists);
	ft_free_swap_list(&lists);
	return (0);
}

void ft_push_swap_resolv(t_swap *lists)
{
	int	i;

	i = 1;
	/*
	while(i < lists->length) {

		if ( lists->a->content < lists->a->next ) { // si l’élément est mal placé

			j = 0;

			while ( T[j] < T[i] ) j++; // cette boucle sort par j = la nouvelle position de l’élément
	
			c = T[i]; // ces 2 lignes servent a translater les cases en avant pour pouvoir insérer l’élément a sa nouvelle position
			for( k = i-1 ; k >= j ; k-- ) T[k+1] = T[k];
			T[j] = c; // l'insertion
		}
		i++;
	}
	*/
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