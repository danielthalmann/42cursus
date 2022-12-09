/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:12:32 by dthalman          #+#    #+#             */
/*   Updated: 2022/01/14 10:30:01 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * @brief retourne la valeur contenu dans l'index de liste
 * 
 * @param lists 
 */
int	ft_get_value(t_list2 *list)
{
	return (((t_number *)list->content)->n);
}

/**
 * @brief retourne l'indexe de l'élément
 * 
 * @param lists 
 */
t_uint	ft_get_index(t_list2 *list)
{
	return (((t_number *)list->content)->i);
}
