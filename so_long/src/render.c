/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:47 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/14 11:33:39 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "game.h"
#include "mlx.h"

int	ft_init_render(t_gl *gl)
{
	t_game	*game;

	game = ft_game();
	game->gl.mlx_ptr = mlx_init();
	if(!game->gl.mlx_ptr)
		return (0);
	game->gl.win_ptr = mlx_new_window(game->gl.mlx_ptr, 500, 500, "so_long");
	if(!game->gl.win_ptr)
		return (0);
	return (1);
}
