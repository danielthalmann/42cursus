/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_loader.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:12:32 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/12 17:53:17 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

/**
 * @brief Charge la liste à partir d'un tableau de chaine de caractère
 * 
 * @param lists 
 * @param len 
 * @param v 
 * @return retourne 1 si tout s'est bien passé
 */
int	ft_internal_load_swap_list(t_swap *lists, char **v, unsigned int len)
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
			return (0);
		}
		n->s = v[i];
		n->n = ft_atol(v[i]);
		lst = ft_lst2new(n);
		ft_lst2add_back(&lists->a.list, lst);
		lists->a.end = lst;
		i++;
	}
	lists->a.length = i;
	lists->b.length = 0;
	return (1);
}

/**
 * @brief Charge la liste à partir d'un tableau de chaine de caractère
 * 
 * @param lists 
 * @param len
 * @param v 
 * @return retourne 1 si tout s'est bien passé
 */
int	ft_load_swap_list(t_swap *lists, char **v, int len)
{
	int	ret;

	if (len < 1)
		return (0);
	if (len == 1)
	{
		v = ft_split(v[0], ' ');
		len = 0;
		while (v[len])
			len++;
		ret = ft_internal_load_swap_list(lists, v, len);
		while (--len > -1)
			free(v[len]);
		free(v);
		return (ret);
	}
	else
		return (ft_internal_load_swap_list(lists, v, len));
}
