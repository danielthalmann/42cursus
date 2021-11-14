/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:26:14 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 13:26:14 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

t_uint	*ft_key_state(void)
{
	static t_uint	state[125];

	return (state);
}

int	ft_input_key(int key, void *param)
{
	t_game	*game;
	char	*msg;

	(void)param;
	game = ft_game();
	if (key == KEY_ESC)
	{
		mlx_destroy_window(game->gl.mlx_ptr, game->gl.win_ptr);
		ft_end_game();
	}
	if (key == KEY_ENTER)
	{
		msg = "ENTER";
		mlx_clear_window(game->gl.mlx_ptr, game->gl.win_ptr);
		mlx_string_put(game->gl.mlx_ptr, game->gl.win_ptr, 10, 10, 255, msg);
	}
	ft_putnbr_fd(key, 1);
	ft_putchar_fd(' ', 1);
	return (0);
}
