/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:36:40 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 02:17:38 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;

	(void)argc;
	(void)argv;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so_long");
	mlx_loop_hook (mlx_ptr, &ft_game_loop, NULL);
	mlx_loop(mlx_ptr);

	return (0);
}
