/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 01:06:44 by dthalman          #+#    #+#             */
/*   Updated: 2021/10/16 01:06:44 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief Alloue (avec malloc(3)) et renvoie un nouvel élément. la variable 
 * content est initialisée à l’aide de la valeur du paramètre content. La
 * variable ’next’ est initialisée à NULL.
 * 
 * @param content value of content
 * @return t_list* 
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->next = 0;
	list->content = content;
	return (list);
}
