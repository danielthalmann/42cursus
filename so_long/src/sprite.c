/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:39:26 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/14 19:31:44 by dthalman         ###   ########.fr       */
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

	t_pos src;
	t_pos dest;
	t_pos isize;

	dest.x = 0;
	dest.y = 0;

	src.x = 0;
	src.y = 0;

	isize.x = 100;
	isize.y = 100;

	ft_draw_image(img_ptr, &(game->gl), src, dest, isize);

/*	
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
*/

}

void	ft_draw_image(void *img_ptr, t_gl *gl, t_pos src, t_pos dest, t_pos size)
{
	unsigned int	*ptr;
	int			bits_per_pixel = 0;
	int			size_line = 0;
	int			endian = 0;
	unsigned int color;
	t_pos	c;

	ptr = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

	ft_printf("bits_per_pixel %d\n", bits_per_pixel);
	ft_printf("size_line %d\n", size_line);
	ft_printf("endian %d\n", endian);
	ft_printf("point %p\n", ptr);
	ft_printf("value %d\n", *ptr);

	c.y = 0;
	while(c.y < size.y)
	{

		c.x = 0;
		while(c.x < size.x)
		{
			color = ((unsigned int*)ptr)[((c.y + src.y) * 1200) + (c.x + src.x)];
			ft_printf("value %d %d %d %d\n", c.x, c.y, color, size.y);
			mlx_pixel_put(gl->mlx_ptr, gl->win_ptr, dest.x + c.x, dest.y + c.y, color);
			c.x++;
		}
		c.y++;	
	}
	

}