/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:28:45 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/12 15:23:41 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

/**
 * @brief Retrouve le même numéro que la list l dans p en arriève
 * 
 * @param l 
 * @param p 
 * @return int 
 */
int	ft_found_backward(t_list2 *l, t_list2 *p)
{
	while (p)
	{
		if (((t_number *)l->content)->n == ((t_number *)p->content)->n)
			return (1);
		p = p->previous;
	}
	return (0);
}

/**
 * @brief Retrouve le même numéro que la list l dans p en avant
 * 
 * @param l 
 * @param p 
 * @return int 
 */
int	ft_found_forward(t_list2 *l, t_list2 *p)
{
	while (p)
	{
		if (((t_number *)l->content)->n == ((t_number *)p->content)->n)
			return (1);
		p = p->next;
	}
	return (0);
}

/**
 * @brief Vérifie si la valeur numérique passé en paramètre est correct
 * 
 * @param l 
 * @return int 
 */
int	ft_is_invalid_num(t_list2 *l)
{
	char	*str;

	str = ((t_number *)l->content)->s;
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '-')
			return (0);
		str++;
	}
	return (1);
}

/**
 * @brief browse the list to verify that number has not duplicata
 * 
 * @param lists 
 * @return int 
 */
int	ft_is_list_valid(t_swap *lists)
{
	t_uint	i;
	t_list2	*l;

	l = lists->a.list;
	i = -1;
	while (l)
	{
		if (++i < ((lists->a.length + 1) / 2))
		{
			if (ft_found_backward(l, l->previous))
				return (0);
			if (ft_found_forward(l, l->next))
				return (0);
		}
		if (!ft_is_invalid_num(l))
			return (0);
		l = l->next;
	}
	return (1);
}
