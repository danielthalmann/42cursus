/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 08:58:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/20 12:27:35 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H
# include "utils.h"
# include "map.h"

t_uint	ft_get_map_pos(t_map *map, int x, int y);
void	ft_set_map_pos(t_uint v, t_map *map, t_uint x, t_uint y);
t_pos	ft_map_pos_to_screen(t_pos m_pos);
#endif
