/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/21 03:28:33 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "game.h"
#include "render.h"
#include "map_utils.h"
#include "libft.h"

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
	tr.src.x = player->anim_index * PLAYER_SPRITE_WIDTH;
	tr.src.y = player->state * PLAYER_SPRITE_HEIGHT;
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
	
	game->player.speed = 3;
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
	game->player.position = ft_map_pos_to_screen(game->map.player_pos);
	game->player.map_position = game->map.player_pos;
	game->player.destination = game->player.position;
	game->player.map_destination = game->map.player_pos;
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
	t_state	state;

	if (player->anim_last_time + player->speed_anim < time)
	{
		player->anim_index++;
		if (player->anim_index >= player->anim_limit[player->state])
			player->anim_index = 0;
		player->anim_last_time = time;
	}
	state.on_walk = PLAYER_ANIM_WALK_B;
	state.on_walk = PLAYER_ANIM_WAIT_B;
	ft_update_player_action(player, game, state);
	state.on_walk = PLAYER_ANIM_WALK_F;
	state.on_walk = PLAYER_ANIM_WAIT_F;
	ft_update_player_action(player, game, state);
	state.on_walk = PLAYER_ANIM_WALK_L;
	state.on_walk = PLAYER_ANIM_WAIT_L;
	ft_update_player_action(player, game, state);
	state.on_walk = PLAYER_ANIM_WALK_R;
	state.on_walk = PLAYER_ANIM_WAIT_R;
	ft_update_player_action(player, game, state);
}

void	ft_update_player_action(t_player *player, t_game *game, t_state s)
{
	if (ft_keys_state()[KEY_UP] && !player->walk)
	{
		if (ft_get_map_pos(&(game->map), player->map_position.x, player->map_position.y - 1) != '1')
		{
			player->walk = 1;
			player->map_destination = player->map_position;
			player->map_destination.y--;
			player->destination = ft_map_pos_to_screen(player->map_destination);
			player->state = s.on_walk;
		}
	}
	if (player->walk)
	{
		if (player->state == s.on_walk)
		{
			player->position.y -= player->speed;
			if (player->position.y < player->destination.y)
				player->position.y = player->destination.y;
			if (ft_compare_pos(&(player->position), &(player->destination)))
			{
				player->map_position = player->map_destination;
				player->state = s.on_stay;
				player->walk = 0;
			}
		}
	}
}