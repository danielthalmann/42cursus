/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 08:58:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/14 09:11:48 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_UTILS_H
# define MAP_UTILS_H
# include "utils.h"
# include "map.h"

t_uint	ft_get_map_pos(t_map *map, int x, int y);
void	ft_set_map_pos(t_uint v, t_map *map, t_uint x, t_uint y);
#endif