/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:11:30 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/24 16:11:30 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Itère sur la liste lst et applique la fonction f au contenu de chaque élément. 
 * Crée une nouvelle liste résultant des applications successives de f. 
 * la fonction del est la pour detruire le contenu d unelement si necessaire
 * 
 * @param lst 
 * @param f 
 * @param del 
 * @return t_list* 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	
}
