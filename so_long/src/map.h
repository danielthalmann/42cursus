/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:21:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/01 11:55:47 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "utils.h"
# include "libft.h"
# define MAP_SPRITE_WIDTH 72
# define MAP_SPRITE_HEIGHT 72

int		ft_load_map(char *filename, t_map *map);
int		ft_load_list_map(t_list *list, t_map *map);
void	ft_free_list_map(t_list *list);
int		ft_free_map(t_map *map);
t_uint	ft_map_count_width(char *s);
void	ft_map_load_sprite(char *f);
void	ft_draw_map(t_map *map);
void	ft_draw_map_pos(t_map *map, t_gl *gl, t_pos pos);
t_uint	ft_get_map_pos(t_map *map, t_uint x, t_uint y);
void	ft_set_map_pos(t_uint v, t_map *map, t_uint x, t_uint y);
t_uint	ft_get_map_pos2(t_map *map, t_pos *pos);
void	ft_set_map_pos2(t_uint v, t_map *map, t_pos *pos);
t_pos	ft_map_pos_to_screen(t_pos m_pos);
int		ft_valid_map(t_map *map);
int		ft_valid_map_isclosed_h(t_map *map);
int		ft_valid_map_isclosed_v(t_map *map);
int		ft_valid_map_caracter(t_map *map);
#endif