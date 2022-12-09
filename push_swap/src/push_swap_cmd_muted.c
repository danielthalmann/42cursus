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

t_list2	**ft_get_cmd_list(void)
{
	static t_list2	*list;

	return (&list);
}

/**
 * @brief Execute a command on lists
 * 
 * @param cmd 
 * @param lists 
 */
int	ft_exec_muted(t_push_swap_cmd cmd, t_swap *lists)
{
	t_list2			**lcmd;
	t_list2			*lst;
	t_push_swap_cmd	*ncmd;

	lcmd = ft_get_cmd_list();
	ncmd = malloc(sizeof(t_push_swap_cmd));
	*ncmd = cmd;
	lst = ft_lst2new(ncmd);
	ft_lst2add_back(lcmd, lst);
	if (ft_exec_swap(cmd, lists, 1))
		return (1);
	if (ft_exec_push(cmd, lists, 1))
		return (1);
	if (ft_exec_rotate(cmd, lists, 1))
		return (1);
	if (ft_exec_rev_rotate(cmd, lists, 1))
		return (1);
	return (0);
}

/**
 * @brief libère de la mémoire la liste
 * 
 * @param lists 
 */
void	ft_free_exec_list(void)
{
	t_list2	**lcmd;

	lcmd = ft_get_cmd_list();
	ft_lst2clear(lcmd, free);
}
