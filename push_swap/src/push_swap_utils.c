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

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void ft_exec(int cmd, t_swap *lists)
{
	if (cmd == CMD_SA)
	{
		ft_swap_a(lists);
		ft_printf("sa\n");
	}
	if (cmd == CMD_SB)
	{
		ft_swap_b(lists);
		ft_printf("sb\n");
	}
	if (cmd == CMD_SS)
	{
		ft_swap_ss(lists);
		ft_printf("ss\n");
	}
	if (cmd == CMD_PA)
	{
		ft_push_a(lists);
		ft_printf("pa\n");
	}
	if (cmd == CMD_PB)
	{
		ft_push_b(lists);
		ft_printf("pb\n");
	}
	if (cmd == CMD_RA)
	{
		ft_rotate_a(lists);
		ft_printf("ra\n");
	}
	if (cmd == CMD_RB)
	{
		ft_rotate_a(lists);
		ft_printf("rb\n");
	}
	if (cmd == CMD_RR)
	{
		ft_rotate_rr(lists);
		ft_printf("rb\n");
	}
	if (cmd == CMD_RRA)
	{
		ft_reverse_rotate_a(lists);
		ft_printf("rra\n");
	}
	if (cmd == CMD_RRB)
	{
		ft_reverse_rotate_b(lists);
		ft_printf("rrb\n");
	}
	if (cmd == CMD_RRR)
	{
		ft_reverse_rotate_rr(lists);
		ft_printf("rrr\n");
	}
	ft_print_swap(lists);
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

	list_a = lists->a.list;
	list_b = lists->b.list;
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

//		if(list_a)
//			ft_printf(" ap %10p an %10p", list_a->previous, list_a->next);
//		if(list_b)
//			ft_printf(" bp %10p bn %10p", list_b->previous, list_b->next);

		if(list_a)
			list_a = list_a->next;
		if(list_b)
			list_b = list_b->next;

		ft_printf("\n");
	}
	ft_printf("%8s%8s\n", "end a", "end b");
	if(lists->a.end)
		ft_printf("%8s", ((t_number*)lists->a.end->content)->s);
	else
		ft_printf("%8s", "");
	if(lists->b.end)
		ft_printf("%8s", ((t_number*)lists->b.end->content)->s);
	else
		ft_printf("%8s", "");
	ft_printf("\n");
	ft_printf("%8s%8s\n", "len a", "len b");
	ft_printf("%8d%8d\n", lists->a.length, lists->b.length);
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
void	ft_load_swap_list(t_swap *lists, char **v, unsigned int len)
{
	unsigned int	i;
	t_number		*n;
	t_list2			*lst;

	ft_memset((void *)lists, 0, sizeof(t_swap));
	i = 0;
	lst = 0;
	while (v[i] && i < len)
	{
		n = malloc(sizeof(t_number));
		if (!n)
		{
			ft_lst2clear(&lists->a.list, free);
			return ;
		}
		n->s = v[i];
		n->n = ft_atoi(v[i]);
		lst = ft_lst2new(n);
		ft_lst2add_back(&lists->a.list, lst);
		lists->a.end = lst;
		i++;
	}
	lists->a.length = i;
	lists->b.length = 0;
}

/**
 * @brief libère de la mémoire les listes
 * 
 * @param lists 
 */
void	ft_free_swap_list(t_swap *lists)
{
	ft_lst2clear(&(lists->a.list), free);
	ft_lst2clear(&(lists->b.list), free);
	lists->a.end = 0;
	lists->b.end = 0;
}
