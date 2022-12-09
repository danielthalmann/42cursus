/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/12/04 11:13:38 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"
#include "render.h"
#include "map.h"
#include "libft.h"
#include "mlx.h"

/**
 * @brief Dessine le joueur a l'ecran
 * 
 * @param player 
 * @param gl 
 */
void	ft_draw_player_pos(t_player *player, t_map *map, t_gl *gl)
{
	t_translation	tr;

	tr.dest = player->position;
	tr.dest.x += PLAYER_SPRITE_OFFSET_L;
	if (player->anim_index < player->anim_limit[player->current_state])
		tr.src.x = player->anim_index * PLAYER_SPRITE_WIDTH;
	else
		tr.src.x = 0;
	tr.src.y = player->current_state * PLAYER_SPRITE_HEIGHT;
	tr.size.x = PLAYER_SPRITE_WIDTH;
	tr.size.y = PLAYER_SPRITE_HEIGHT;
	ft_draw_map_pos(map, gl, player->map_position);
	ft_draw_map_pos(map, gl, player->map_destination);
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
	game->player.speed = 10;
	game->player.speed_anim = 1;
	game->player.anim_last_time = 0;
	game->player.anim_index = 0;
	game->player.walk = 0;
	game->player.anim_limit[PLAYER_ANIM_WAIT_F] = 3;
	game->player.anim_limit[PLAYER_ANIM_WAIT_L] = 3;
	game->player.anim_limit[PLAYER_ANIM_WAIT_B] = 1;
	game->player.anim_limit[PLAYER_ANIM_WAIT_R] = 3;
	game->player.anim_limit[PLAYER_ANIM_WALK_F] = 10;
	game->player.anim_limit[PLAYER_ANIM_WALK_L] = 10;
	game->player.anim_limit[PLAYER_ANIM_WALK_B] = 10;
	game->player.anim_limit[PLAYER_ANIM_WALK_R] = 10;
	game->player.current_state = PLAYER_ANIM_WAIT_F;
	game->player.end_state = PLAYER_ANIM_WAIT_F;
	game->player.position = ft_map_pos_to_screen(game->map.player_pos);
	game->player.map_position = game->map.player_pos;
	game->player.destination = game->player.position;
	game->player.map_destination = game->map.player_pos;
	if (!ft_player_load_sprite("media/player.xpm", game))
		ft_end_game("Le sprite du joueur n'a pas pu être chargé.");
	return (1);
}

/**
 * @brief Charge le sprite pour le joueur
 * 
 * @param f 
 */
void	*ft_player_load_sprite(char *f, t_game *game)
{
	t_size	s;
	void	*(*fn)();
	int		*w;
	int		*h;

	w = (int *)&(s.w);
	h = (int *)&(s.h);
	fn = &mlx_xpm_file_to_image;
	game->player.img_ptr = (*fn)(game->gl.mlx_ptr, f, w, h);
	return (game->player.img_ptr);
}

/**
 * @brief Libere de la memoire l'image du joueur
 * 
 * @param map 
 */
void	ft_free_player(t_player *player)
{
	t_game	*game;

	game = ft_game();
	if (player->img_ptr)
		mlx_destroy_image(game->gl.mlx_ptr, player->img_ptr);
}
