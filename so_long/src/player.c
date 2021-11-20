/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/20 08:58:13 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"
#include "render.h"
#include "libft.h"

/**
 * @brief Dessine le joueur a l'ecran
 * 
 * @param player 
 * @param gl 
 */
void	ft_draw_player_pos(t_player *player, t_gl *gl)
{
	t_translation	tr;

	tr.dest.x = player->position.x;
	tr.dest.y = player->position.y;
	tr.src.x = player->anim_index * PLAYER_SPRITE_WIDTH;
	tr.src.y = player->state * PLAYER_SPRITE_HEIGHT;
	tr.size.x = PLAYER_SPRITE_WIDTH;
	tr.size.y = PLAYER_SPRITE_HEIGHT;
	ft_draw_image(player->img_ptr, gl, tr);
}

/**
 * @brief Initialise les paramètres globaux du joueur
 * 
 * @param player 
 * @param game 
 * @return int 
 */
int	ft_init_player(t_game *game)
{
	game->player.speed = 20;
	game->player.speed_anim = 2;
	game->player.anim_last_time = 0;
	game->player.anim_index = 0;
	game->player.anim_limit[PLAYER_ANIM_WAIT_F] = 3;
	game->player.anim_limit[PLAYER_ANIM_WAIT_L] = 3;
	game->player.anim_limit[PLAYER_ANIM_WAIT_B] = 1;
	game->player.anim_limit[PLAYER_ANIM_WAIT_R] = 3;
	game->player.anim_limit[PLAYER_ANIM_WALK_F] = 10;
	game->player.anim_limit[PLAYER_ANIM_WALK_L] = 10;
	game->player.anim_limit[PLAYER_ANIM_WALK_B] = 10;
	game->player.anim_limit[PLAYER_ANIM_WALK_R] = 10;
	game->player.state = PLAYER_ANIM_WALK_F;
	ft_player_load_sprite("media/player.png", game);
}

/**
 * @brief Charge dans la map le sprite pour la map
 * 
 * @param f 
 */
void	ft_player_load_sprite(char *f, t_game *game)
{
	t_size	s;
	void	*(*fn)();
	int		*w;
	int		*h;

	w = (int *)&(s.w);
	h = (int *)&(s.h);
	fn = &mlx_png_file_to_image;
	game->player.img_ptr = (*fn)(game->gl.mlx_ptr, f, w, h);
}

/**
 * @brief met à jour l'etat du joueur
 * 
 * @param player 
 * @param time 
 */
void	ft_update_player(t_player *player, t_game *game, int time)
{
	if (player->anim_last_time + player->speed_anim < time)
	{
		player->anim_index++;
		if (player->anim_index >= player->anim_limit[player->state])
			player->anim_index = 0;
		player->anim_last_time = time;
	}
}
