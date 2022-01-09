/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:03:54 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/09 13:13:33 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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
enum push_swap_cmd
{
	sa,
	sb
};
typedef unsigned int	t_uint;
typedef struct s_stack
{
	t_list2	*list;
	t_list2	*end;
	t_uint	length;
}	t_stack;
typedef struct s_swap
{
	t_stack	a;
	t_stack	b;
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
void	ft_swap_list(t_stack *stack);
void	ft_push_a(t_swap *lists);
void	ft_push_b(t_swap *lists);
void	ft_push_a_b(t_stack *a, t_stack *b);
void	ft_rotate_a(t_swap *lists);
void	ft_rotate_b(t_swap *lists);
void	ft_rotate_rr(t_swap *lists);
void	ft_rotate_list(t_stack *stack);
void	ft_reverse_rotate_a(t_swap *lists);
void	ft_reverse_rotate_b(t_swap *lists);
void	ft_reverse_rotate_rr(t_swap *lists);
void	ft_reverse_rotate_list(t_stack *stack);
void	ft_print_swap(t_swap *lists);
void	ft_load_swap_list(t_swap *lists, char **v, unsigned int len);
void	ft_free_swap_list(t_swap *lists);
int		ft_is_list_valid(t_swap *lists);
#endif