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

int	ft_game_loop()
{
/*
	static int i;

	ft_putstr_fd("loop\n", 1);

	i++;
	ft_putnbr_fd(i, 1);
*/
	return (0);
}

t_game	*ft_game()
{
	static t_game	game;

	return (&game);
}

int ft_init_game()
{
	t_game	*game;

	game = ft_game();
	game->is_init = 1;
	game->gl.mlx_ptr = mlx_init();
	game->gl.win_ptr = mlx_new_window(game->gl.mlx_ptr, 500, 500, "so_long");
	mlx_key_hook(game->gl.win_ptr, &ft_input_key, (void *)0);
	mlx_loop_hook(game->gl.mlx_ptr, &ft_game_loop, (void *)0);
	ft_load_image("media/player.png");
	mlx_loop(game->gl.mlx_ptr);
	return (0);
}