/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:03:54 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/04 18:57:16 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# include "list2.h"
# define CMD_SA 0
# define CMD_SB 1
# define CMD_SS 2
# define CMD_PA 3
# define CMD_PB 4
# define CMD_RA 5
# define CMD_RB 6
# define CMD_RR 7
# define CMD_RRA 8
# define CMD_RRB 9
# define CMD_RRR 10
# define CMD_LENGTH 11

typedef unsigned int t_uint;
typedef struct s_swap
{
	t_list2	*a;
	t_list2	*a_end;
	t_uint	a_length;
	t_list2	*b;
	t_list2	*b_end;
	t_uint	b_length;
}	t_swap;
typedef struct s_number
{
	int		n;
	char	*s;
}	t_number;
int		ft_a_lt_b(t_list2 *a, t_list2 *b);
int		ft_a_gt_b(t_list2 *a, t_list2 *b);
int		ft_a_eq_b(t_list2 *a, t_list2 *b);
void	ft_exec(int cmd, t_swap *lists);
void	ft_swap_a(t_swap *lists);
void	ft_swap_b(t_swap *lists);
void	ft_swap_ss(t_swap *lists);
void	ft_push_a(t_swap *lists);
void	ft_push_b(t_swap *lists);
void	ft_rotate_a(t_swap *lists);
void	ft_rotate_b(t_swap *lists);
void	ft_rotate_rr(t_swap *lists);
void	ft_reverse_rotate_a(t_swap *lists);
void	ft_reverse_rotate_b(t_swap *lists);
void	ft_reverse_rotate_rr(t_swap *lists);
void	ft_print_swap(t_swap *lists);
void	ft_load_swap_list(t_swap *lists, char **v);
void	ft_free_swap_list(t_swap *lists);
#endif