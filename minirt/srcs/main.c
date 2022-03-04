/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:17:13 by dthalman          #+#    #+#             */
/*   Updated: 2022/03/04 23:17:13 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "glmath.h"
#include <stdlib.h>
#include <stdio.h>
# define MLX_EVT_KEYDN 2
# define MLX_EVT_KEYUP 3
# define MLX_EVT_DESTROY 17

int	on_close(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		width = 640;
	int		height = 480;
	int		x, y ;
	unsigned int *ptr;
	int bpp, sl, endian;
	t_color	c;

	c.r = 0;
	c.g = 255;
	c.b = 255; // r
	c.a = 0;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, width, height, "minirt");
	mlx_hook(win_ptr, MLX_EVT_DESTROY, 0L, &on_close, (void *)0);

	img_ptr = mlx_new_image(mlx_ptr, width, height);

	ptr = (unsigned int *)mlx_get_data_addr(img_ptr, &(bpp), &(sl), &(endian));
	y = 0;

	printf("%X \n", color_int(&c));

	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			ptr[x + (y * width)] = color_int(&c);
			//mlx_pixel_put(img_ptr, win_ptr, x, y, color_int(&c));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);	
	mlx_loop(mlx_ptr);

	return (0);
}