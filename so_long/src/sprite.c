/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:39:26 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/14 09:24:32 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "util.h"

void	ft_load_image(char *filename)
{
	t_game	*game;
	t_size	size;
	void	*img_ptr;

	size.width = 0;
	size.height = 0;
	game = ft_game();
	img_ptr = mlx_png_file_to_image(game->gl.mlx_ptr, filename, (int *)&(size.width), (int *)&(size.height));

	
	t_uint *point = 0;
	int bits_per_pixel = 0;
	int size_line = 0;
	int endian = 0;

	point = (t_uint *)mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

	ft_printf("bits_per_pixel %d\n", bits_per_pixel);
	ft_printf("size_line %d\n", size_line);
	ft_printf("endian %d\n", endian);
	ft_printf("point %p\n", point);
	ft_printf("value %d\n", *point);

	for(int y = 100; y <  204; y++)
		for(int x = 100; x < 220; x++)
		{
			//ft_printf("value %d\n", point[ (y * 64) + x]);
			mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, x-100, y -100, ((unsigned int)point[((y ) * 1200) + (x )]));

		}

	//mlx_put_image_to_window  (game->gl.mlx_ptr, game->gl.win_ptr, img_ptr, 2, 2);
}

void	ft_draw_image(void *img_ptr, t_gl *gl, t_position src, t_position dest)
{
	char	*ptr;
	int		bits_per_pixel = 0;
	int		size_line = 0;
	int		endian = 0;

	ptr = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);	
}