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

int	ft_game_loop(void)
{
	static int	i;

	i++;
	return (0);
}

t_game	*ft_game(void)
{
	static t_game	game;

	return (&game);
}

int	ft_init_game(void)
{
	t_game	*game;

	game = ft_game();
	game->is_init = 1;
	// https://harm-smits.github.io/42docs/libs/minilibx/events.html
	// int	mlx_hook(game->gl.win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
	// example :  mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_key_hook(game->gl.win_ptr, &ft_input_key, (void *)0);
	mlx_loop_hook(game->gl.mlx_ptr, &ft_game_loop, (void *)0);
	ft_load_image("media/player.png");
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
