/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 09:54:04 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/24 09:54:04 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Ajoute l’élément new à la fin de la liste.
 * 
 * @param alst 
 * @param new 
 */
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*llast;

	if(!*alst)
		*alst = new;
	else
	{
		llast = ft_lstlast(*alst);
		llast->next = new;
	}
}
