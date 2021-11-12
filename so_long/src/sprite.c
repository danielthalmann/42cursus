/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:39:26 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 14:57:05 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

void	ft_load_image(char *filename)
{
	t_game	*game;
	t_size	size;
	void	*img_ptr;

	size.width = 0;
	size.height = 0;
	game = ft_game();
	img_ptr = mlx_png_file_to_image(game->gl.mlx_ptr, filename, (int *)&(size.width), (int *)&(size.height));

	
	char *point = 0;
	int bits_per_pixel = 0;
	int size_line = 0;
	int endian = 0;

	point = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

	ft_printf("bits_per_pixel %d\n", bits_per_pixel);
	ft_printf("size_line %d\n", size_line);
	ft_printf("endian %d\n", endian);
	ft_printf("point %p\n", point);
	ft_printf("value %d\n", *point);

	for(int y = 0; y <  100; y++)
		for(int x = 0; x < 1200; x++)
		{
			//ft_printf("value %d\n", point[ (y * 64) + x]);
			mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, x, y, point[ ((y * 4) * 1200) + (x * 4)]);

		}

	//mlx_put_image_to_window  (game->gl.mlx_ptr, game->gl.win_ptr, img_ptr, 2, 2);
}