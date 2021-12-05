/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:12:32 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/04 19:31:42 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include "libft.h"

/**
 * @brief swap the first 2 elements at the top of stacka. Do nothing if thereis
 * only one or no elements
 * 
 * @param lists 
 */
void ft_swap_a(t_swap *lists)
{
	t_list2 *a_nnext;
	t_list2 *a_next;

	if (!lists->a)
		return ;
	if (!lists->a->next)
		return ;	
	a_next = lists->a->next;
	a_nnext = lists->a->next->next;
	if (lists->a_last == a_next)
		lists->a_last = lists->a;
	a_next->next = lists->a;
	a_next->previous = 0;
	lists->a->next = a_nnext;
	lists->a->previous = a_next;
	lists->a = a_next;
}

/**
 * @brief swap b- swap the first 2 elements at the top of stackb. 
 * Do nothing if thereis only one or no elements).
 * 
 * @param lists 
 */
void ft_swap_b(t_swap *lists)
{
	t_list2 *b_nnext;
	t_list2 *b_next;

	if (!lists->b)
		return ;
	if (!lists->b->next)
		return ;	
	b_next = lists->b->next;
	b_nnext = lists->b->next->next;
	if (lists->b_last == b_next)
		lists->b_last = lists->b;
	b_next->next = lists->b;
	b_next->previous = 0;
	lists->b->next = b_nnext;
	lists->b->previous = b_next;
	lists->b = b_next;
}

/**
 * @brief sa and sb at the same time.
 * 
 * @param lists 
 */
void ft_swap_ss(t_swap *lists)
{
	ft_swap_a(lists);
	ft_swap_a(lists);
}

/**
 * @brief push a take the first element at the top ofband put it at the top ofa.
 * Do nothing if bis empty.
 * 
 * @param lists 
 */
void ft_swap_pa(t_swap *lists)
{
	t_list2 *a_next;

	if (!lists->a)
		return;
	if (lists->a_last == lists->a)
		lists->a_last = lists->a->previous;
	a_next = lists->a->next;
	lists->a->next = lists->b;
	lists->a->previous = 0;
	lists->b->previous = lists->a;
	lists->b = lists->a;
	lists->a = a_next;
	if (lists->a)
		lists->a->previous = 0;
}

/**
 * @brief pb :push b- take the first element at the top ofaand put it at the
 * top of b. Donothing ifais empty.
 * 
 * @param lists 
 */
void ft_swap_pb(t_swap *lists)
{
	t_list2 *b_next;

	if (!lists->b)
		return;
	if (lists->b_last == lists->b)
		lists->b_last = lists->b->previous;
	b_next = lists->b->next;
	lists->b->next = lists->b;
	lists->b->previous = 0;
	lists->a->previous = lists->b;
	lists->a = lists->b;
	lists->b = b_next;
	if (lists->b)
		lists->b->previous = 0;
}

/**
 * @brief rotate a- shift up all elements of stackaby 1. The first element 
 * becomes the last one.
 * 
 * @param lists 
 */
void ft_swap_ra(t_swap *lists)
{
	(void) lists;
}

/**
 * @brief rotate b- shift up all elements of stackbby 1. The first element 
 * becomes the last one.
 * 
 * @param lists 
 */
void ft_swap_rb(t_swap *lists)
{
	(void) lists;
}

/**
 * @brief ra and rb at the same time.
 * 
 * @param lists 
 */
void ft_swap_rr(t_swap *lists)
{
	(void) lists;
}

/**
 * @brief reverse rotate a- shift down all elements of stackaby 1. The last 
 * element becomes the first one.7
 * 
 * @param lists 
 */
void ft_swap_rra(t_swap *lists)
{
	(void) lists;
}

/**
 * @brief reverse rotate b- shift down all elements of stackbby 1. The last 
 * element becomes the first one.
 * 
 * @param lists 
 */
void ft_swap_rrb(t_swap *lists)
{
	(void) lists;
}

/**
 * @brief rra and rrb at the same time.
 * 
 * @param lists 
 */
void ft_swap_rrr(t_swap *lists)
{
	(void) lists;
}

void ft_test()
{
	int	j;
	int	i;
	int N = 0;
	int	T[6];
	int	c;
	// Tri a bulle

	for(j=1;j<=N;j++) // pour faire l'operation N fois
		for(i=0; i < N-1; i++)
			if ( T[i] > T[i+1] ) {
					c = T[i];
					T[i] = T[i+1];
					T[i+1] = c;
			}

	// Tri par permutation
	//cet algorithme consiste a parcourir le tableau jusqu’à ce qu'il trouve un élément inférieur 
	// que le précédent ( mal placé ) , il prend cet élément et il le rang a sa place dans le tableau , 
	// et il continue le parcours jusqu’à la fin .
	// et affin de ne pas écraser les valeurs du tableau il faut réaliser une translation des valeurs a l'aide d'une boucle .

	int k;

	for(i=1;i<N;i++) {

		if ( T[i] < T[i-1] ) { // si l’élément est mal placé

			j = 0;

			while ( T[j] < T[i] ) j++; // cette boucle sort par j = la nouvelle position de l’élément
	
	c = T[i]; // ces 2 lignes servent a translater les cases en avant pour pouvoir insérer l’élément a sa nouvelle position
			for( k = i-1 ; k >= j ; k-- ) T[k+1] = T[k];
	T[j] = c; // l'insertion
		}
	}

}

/**
 * @brief rra and rrb at the same time.
 * 
 * @param lists 
 */
void ft_print_swap(t_swap *lists)
{
	t_list2 *list_a;
	t_list2 *list_b;

	list_a = lists->a;
	list_b = lists->b;
	ft_printf("%8s%8s\n", "list a", "list b");
	while (list_a || list_b)
	{
		if(list_a)
		{
			ft_printf("%8s", ((t_number*)list_a->content)->s);
			list_a = list_a->next;
		}
		else
			ft_printf("%8s", "");
		if(list_b)
		{
			ft_printf("%8s", ((t_number*)list_b->content)->s);
			list_b = list_b->next;
		}
		else
			ft_printf("%8s", "");
		ft_printf("\n");
	}
}