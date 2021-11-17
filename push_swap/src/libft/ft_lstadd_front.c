/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 09:34:13 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/24 09:34:13 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Ajoute l’élément ’new’ au début de la liste.
 * 
 * @param alst 
 * @param new 
 */
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (*alst)
		new->next = (*alst);
	*alst = new;
}
