/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:21:01 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/03 10:51:20 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"
#include "render.h"

/**
 * @brief Charge dans la map le sprite pour la map
 * 
 * @param f 
 */
void	*ft_map_load_sprite(char *f)
{
	t_game	*game;
	void	*(*fn)();
	int		w;
	int		h;

	fn = &mlx_xpm_file_to_image;
	game = ft_game();
	game->map.img_ptr = (*fn)(game->gl.mlx_ptr, f, &w, &h);
	return (game->map.img_ptr);
}

/**
 * @brief Dessine a l'écran la carte
 * 
 * @param map 
 */
void	ft_draw_map(t_map *map)
{
	t_game	*game;
	t_pos	pos;

	game = ft_game();
	pos.y = -1;
	while (++pos.y < map->size.h)
	{
		pos.x = -1;
		while (++pos.x < map->size.w)
		{
			ft_draw_map_pos(map, &(game->gl), pos);
		}
	}
}
