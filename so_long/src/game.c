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
#include "score.h"

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
	if ((i % 10) == 0)
		ft_draw_score(&game->score, game, &game->gl);
	return (0);
}

/**
 * @brief retourne la structure static contenant tout l'état du jeu
 * 
 * @return t_game* 
 */
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
	mlx_hook(game->gl.win_ptr, MLX_EVT_DESTROY, 0L, &ft_on_close, (void *)0);
	mlx_loop_hook(game->gl.mlx_ptr, &ft_game_loop, (void *)0);
	if (!ft_map_load_sprite("media/map.xpm"))
		ft_end_game("Le sprite de la map n'a pas pu être chargé.");
	ft_init_player(game);
	ft_draw_map(&(game->map));
	ft_init_score(game);
	ft_draw_score_init(&game->score, &game->gl);
	mlx_loop(game->gl.mlx_ptr);
	return (1);
}

/**
 * @brief Evénement lors de la fermeture de la fenètre
 * 
 * @return int 
 */
int	ft_on_close(void)
{
	ft_end_game(0);
	return (1);
}

/**
 * @brief arret le jeu et nettoye tout de la memoire
 * 
 * @param error on peut indiquez un message d'erreur 
 */
void	ft_end_game(char *error)
{
	t_game	*game;

	game = ft_game();
	ft_free_map(&(game->map));
	ft_free_player(&(game->player));
	ft_free_score(&game->score);
	if (error)
		ft_printf("Error\n%s\n", error);
	exit(0);
}
