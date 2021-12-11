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
#include <stdlib.h>

void ft_exec(int cmd, t_swap *lists)
{
	if (cmd == PS_CMD_SA)
	{
		ft_swap_a(lists);
		ft_printf("sa\n");
	}
	if (cmd == PS_CMD_SB)
	{
		ft_swap_b(lists);
		ft_printf("sb\n");
	}
	if (cmd == PS_CMD_SS)
	{
		ft_swap_ss(lists);
		ft_printf("ss\n");
	}
	if (cmd == PS_CMD_PA)
	{
		ft_push_a(lists);
		ft_printf("pa\n");
	}
	if (cmd == PS_CMD_PB)
	{
		ft_push_b(lists);
		ft_printf("pb\n");
	}
	if (cmd == PS_CMD_RA)
	{
		ft_rotate_a(lists);
		ft_printf("ra\n");
	}
	if (cmd == PS_CMD_RB)
	{
		ft_rotate_a(lists);
		ft_printf("rb\n");
	}
	if (cmd == PS_CMD_RR)
	{
		ft_rotate_rr(lists);
		ft_printf("rb\n");
	}
	if (cmd == PS_CMD_RRA)
	{
		ft_reverse_rotate_a(lists);
		ft_printf("rra\n");
	}
	if (cmd == PS_CMD_RRB)
	{
		ft_reverse_rotate_b(lists);
		ft_printf("rrb\n");
	}
	if (cmd == PS_CMD_RRR)
	{
		ft_reverse_rotate_rr(lists);
		ft_printf("rrr\n");
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
			ft_printf("%8s", ((t_number*)list_a->content)->s);
		else
			ft_printf("%8s", "");
		if(list_b)
			ft_printf("%8s", ((t_number*)list_b->content)->s);
		else
			ft_printf("%8s", "");

		if(list_a)
			ft_printf(" ap %10p an %10p", list_a->previous, list_a->next);
		if(list_b)
			ft_printf(" bp %10p bn %10p", list_b->previous, list_b->next);

		if(list_a)
			list_a = list_a->next;
		if(list_b)
			list_b = list_b->next;

		ft_printf("\n");
	}
	ft_printf("%8s%8s\n", "end a", "end b");
	if(lists->a_end)
		ft_printf("%8s", ((t_number*)lists->a_end->content)->s);
	else
		ft_printf("%8s", "");
	if(lists->b_end)
		ft_printf("%8s", ((t_number*)lists->b_end->content)->s);
	else
		ft_printf("%8s", "");
	ft_printf("\n");
	ft_printf("%8s%8s\n", "len a", "len b");
	ft_printf("%8d%8d\n", lists->a_length, lists->b_length);
	ft_printf("\n\n");
}

/**
 * @brief Charge la liste à partir d'un tableau de chaine de caractère
 * 
 * @param lists 
 * @param l 
 * @param v 
 * @return t_list2* 
 */
void	ft_load_swap_list(t_swap *lists, unsigned int l, char **v)
{
	unsigned int	i;
	t_number		*n;
	t_list2			*lst;

	ft_memset((void *)lists, 0, sizeof(t_swap));
	i = -1;
	lst = 0;
	while (++i < l)
	{
		n = malloc(sizeof(t_number));
		if (!n)
		{
			ft_lst2clear(&lists->a, free);
			return ;
		}
		n->s = v[i];
		n->n = ft_atoi(v[i]);
		lst = ft_lst2new(n);
		ft_lst2add_back(&lists->a, lst);
		lists->a_end = lst;
	}
	lists->a_length = l;
	lists->b_length = 0;
}

/**
 * @brief libère de la mémoir les listes
 * 
 * @param lists 
 */
void	ft_free_swap_list(t_swap *lists)
{
	ft_lst2clear(&(lists->a), free);
	ft_lst2clear(&(lists->b), free);
	lists->a_end = 0;
	lists->b_end = 0;
}
