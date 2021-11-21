/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:26:14 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 13:26:14 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "input.h"
#include "map.h"
#include "player.h"

/**
 * @brief boucle du jeux
 * 
 * @return int 
 */
int	ft_game_loop(void)
{
	t_game		*game;
	static int	i;

	i++;
	game = ft_game();
	ft_update_player(&(game->player), game, i);
	ft_draw_player_pos(&(game->player), &(game->map), &(game->gl));
	return (0);
}

t_game	*ft_game(void)
{
	static t_game	game;

	return (&game);
}

/**
 * @brief initialise le jeu
 * On peut trouver des informations sur les evenement a l'adresse suivante :
 * https://harm-smits.github.io/42docs/libs/minilibx/events.html
 * 
 * @return int 
 */
int	ft_init_game(void)
{
	t_game	*game;

	game = ft_game();
	game->is_init = 1;
	mlx_hook(game->gl.win_ptr, MLX_EVT_KEYDN, 1L, &ft_in_key_down, (void *)0);
	mlx_hook(game->gl.win_ptr, MLX_EVT_KEYUP, 2L, &ft_in_key_up, (void *)0);
	mlx_loop_hook(game->gl.mlx_ptr, &ft_game_loop, (void *)0);
	ft_map_load_sprite("media/map.png");
	ft_init_player(game);
	ft_draw_map(&(game->map));
	mlx_loop(game->gl.mlx_ptr);
	return (1);
}

void	ft_end_game(void)
{
	t_game	*game;

	game = ft_game();
	ft_free_map(&(game->map));
	exit(0);
}
