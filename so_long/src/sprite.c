/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:39:26 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/14 16:16:40 by dthalman         ###   ########.fr       */
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

	t_position src;
	t_position dest;
	t_position isize;
	
	src.x = 100;
	src.y = 100;
	
	dest.x = 0;
	dest.y = 0;

	isize.x = 200;
	isize.y = 200;

	ft_draw_image(img_ptr, &(game->gl), src, dest, isize);

/*	
	t_uint *point = 0;
	int bits_per_pixel = 0;
	int size_line = 0;
	int endian = 0;

	point = (t_uint *)mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

	for(int y = 100; y <  204; y++)
		for(int x = 100; x < 220; x++)
		{
			//ft_printf("value %d\n", point[ (y * 64) + x]);
			mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, x-100, y -100, ((unsigned int)point[((y ) * 1200) + (x )]));

		}
*/
	//mlx_put_image_to_window  (game->gl.mlx_ptr, game->gl.win_ptr, img_ptr, 2, 2);
}

void	ft_draw_image(void *img_ptr, t_gl *gl, t_position src, t_position dest, t_position size)
{
	char		*ptr;
	int			bits_per_pixel = 0;
	int			size_line = 0;
	int			endian = 0;
	t_position	c;

	c.x = 0;
	c.y = 0;
	ptr = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	
	ft_printf("bits_per_pixel %d\n", bits_per_pixel);
	ft_printf("size_line %d\n", size_line);
	ft_printf("endian %d\n", endian);
	ft_printf("point %p\n", ptr);
	ft_printf("value %d\n", *ptr);

	while(dest.y + c.y < dest.y + size.y)
	{
		while(dest.x + c.x < dest.x + size.x)
		{
			mlx_pixel_put(gl->mlx_ptr, gl->win_ptr, dest.x, dest.y, ((unsigned int*)ptr)[((src.y + c.y) * (size_line / (bits_per_pixel / 8))) + (src.x + c.x)]);
			c.x++;
		}
		c.y++;
	}
	

}