/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 07:43:01 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/13 20:21:08 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list2.h"
#include "push_swap.h"
#include "libft.h"
#include "main.h"

int	ft_exec_mov(char *str, t_swap *lists)
{
	if (!ft_strncmp(str, "sa\n", 3))
		return (ft_exec_muted(sa, lists));
	if (!ft_strncmp(str, "sb\n", 3))
		return (ft_exec_muted(sb, lists));
	if (!ft_strncmp(str, "ss\n", 3))
		return (ft_exec_muted(ss, lists));
	if (!ft_strncmp(str, "pa\n", 3))
		return (ft_exec_muted(pa, lists));
	if (!ft_strncmp(str, "pb\n", 3))
		return (ft_exec_muted(pb, lists));
	if (!ft_strncmp(str, "ra\n", 3))
		return (ft_exec_muted(ra, lists));
	if (!ft_strncmp(str, "rb\n", 3))
		return (ft_exec_muted(rb, lists));
	if (!ft_strncmp(str, "rr\n", 3))
		return (ft_exec_muted(rr, lists));
	if (!ft_strncmp(str, "rra\n", 4))
		return (ft_exec_muted(rra, lists));
	if (!ft_strncmp(str, "rrb\n", 4))
		return (ft_exec_muted(rrb, lists));
	if (!ft_strncmp(str, "rrr\n", 4))
		return (ft_exec_muted(rrr, lists));
	return (0);
}

int	ft_read_stdin(t_swap *lists)
{
	char	*str;
	int		ret;

	str = get_next_line(0);
	while (str)
	{
		ret = ft_exec_mov(str, lists);
		free(str);
		if (!ret)
			return (0);
		str = get_next_line(0);
	}
	if (str)
	{
		ret = ft_exec_mov(str, lists);
		free(str);
		if (!ret)
			return (0);
	}
	return (1);
}

void	ft_error(char *str)
{
	ft_fprintf(2, str);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_swap	lists;

	if (argc < 2)
		return (0);
	if (!ft_load_swap_list(&lists, ++argv, argc - 1))
		ft_error("Error\n");
	if (ft_is_list_valid(&lists))
	{
		if (!ft_read_stdin(&lists))
			ft_fprintf(2, "Error\n");
		else
		{		
			if (ft_is_list_sorted(lists.a.list))
				ft_fprintf(1, "OK\n");
			else
				ft_fprintf(2, "Error\n");
		}
	}
	else
		ft_fprintf(2, "Error\n");
	ft_free_swap_list(&lists);
	ft_free_exec_list();
	return (0);
}
