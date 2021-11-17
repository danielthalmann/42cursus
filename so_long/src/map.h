/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:21:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/17 17:53:54 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "utils.h"
# include "libft.h"
# include "player.h"
# define MAP_SPRITE_WIDTH 72
# define MAP_SPRITE_HEIGHT 72

typedef struct s_map
{
	t_size	size;
	t_uint	*coord;
	t_pos	player_pos;
	t_pos	exit;
	t_list	*coll;
	void	*img_ptr;
}	t_map;
int		ft_load_map(char *filename, t_map *map);
int		ft_load_list_map(t_list *list, t_map *map);
void	ft_free_list_map(t_list *list);
void	ft_free_map(t_map *map);
t_uint	ft_map_count_width(char *s);
void	ft_map_load_sprite(char *f);
void	ft_draw_map(t_map *map);
void	ft_draw_map_pos(t_map *map, t_gl *gl, t_uint x, t_uint y);
#endif