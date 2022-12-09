/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:12:32 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/14 14:48:48 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

int	ft_print_exec_next(t_list2	**p, t_push_swap_cmd cmd_rr, char *rr, char *rx)
{
	if ((*p)->next && *((t_push_swap_cmd *)(*p)->next->content) == cmd_rr)
	{
		ft_printf(rr);
		*p = (*p)->next;
		*p = (*p)->next;
		return (1);
	}
	else
		ft_printf(rx);
	return (0);
}

void	ft_print_exec_list_intern(t_list2 *p)
{
	if (*((t_push_swap_cmd *)p->content) == sa)
		ft_printf("sa\n");
	if (*((t_push_swap_cmd *)p->content) == sb)
		ft_printf("sb\n");
	if (*((t_push_swap_cmd *)p->content) == ss)
		ft_printf("ss\n");
	if (*((t_push_swap_cmd *)p->content) == pa)
		ft_printf("pa\n");
	if (*((t_push_swap_cmd *)p->content) == pb)
		ft_printf("pb\n");
	if (*((t_push_swap_cmd *)p->content) == rr)
		ft_printf("rr\n");
	if (*((t_push_swap_cmd *)p->content) == rrr)
		ft_printf("rrr\n");
}

/**
 * @brief libère de la mémoire la liste
 * 
 * @param lists 
 */
void	ft_print_exec_list(void)
{
	t_list2	**lcmd;
	t_list2	*p;

	lcmd = ft_get_cmd_list();
	p = *lcmd;
	while (p)
	{
		ft_print_exec_list_intern(p);
		if (*((t_push_swap_cmd *)p->content) == ra)
			if (ft_print_exec_next(&p, rb, "rr\n", "ra\n"))
				continue ;
		if (*((t_push_swap_cmd *)p->content) == rb)
			if (ft_print_exec_next(&p, ra, "rr\n", "rb\n"))
				continue ;
		if (*((t_push_swap_cmd *)p->content) == rra)
			if (ft_print_exec_next(&p, rrb, "rrr\n", "rra\n"))
				continue ;
		if (*((t_push_swap_cmd *)p->content) == rrb)
			if (ft_print_exec_next(&p, rra, "rrr\n", "rrb\n"))
				continue ;
		p = p->next;
	}
}
