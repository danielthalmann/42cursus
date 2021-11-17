/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/17 18:13:43 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"
#include "render.h"


/**
 * @brief Charge dans la map le sprite pour la map
 * 
 * @param f 
 */
void	ft_player_load_sprite(char *f)
{
	t_game			*game;
	t_size			s;
	void			*(*fn)();

	fn = &mlx_png_file_to_image;
	game = ft_game();
	game->player.img_ptr = (*fn)(game->gl.mlx_ptr, f, (int *)&(s.w), (int *)&(s.h));
}

void	ft_draw_player_pos(t_player *player, t_gl *gl)
{
	t_translation	tr;

	tr.dest.x = player->position.x;
	tr.dest.y = player->position.y;
	tr.src.x = 0;
	tr.src.y = 0;
	tr.size.x = PLAYER_SPRITE_WIDTH;
	tr.size.y = PLAYER_SPRITE_HEIGHT;
	ft_draw_image(player->img_ptr, gl, tr);
}