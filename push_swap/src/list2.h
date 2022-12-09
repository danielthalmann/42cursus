/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:03:54 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/04 18:53:57 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST2_H
# define LIST2_H

typedef struct s_list2
{
	void			*content;
	struct s_list2	*next;
	struct s_list2	*previous;
}	t_list2;

t_list2	*ft_lst2new(void *content);
t_list2	*ft_lst2last(t_list2 *lst);
void	ft_lst2add_back(t_list2 **alst, t_list2 *new);
void	ft_lst2add_front(t_list2 **alst, t_list2 *new);
void	ft_lst2delone(t_list2 *lst, void (*del)(void*));
void	ft_lst2clear(t_list2 **lst, void (*del)(void*));
#endif