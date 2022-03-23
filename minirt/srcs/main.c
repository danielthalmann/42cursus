/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:17:13 by dthalman          #+#    #+#             */
/*   Updated: 2022/03/12 10:25:12 by dthalman         ###   ########.fr       */
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

void around(t_scene *scene, int x, int y, void *data)
{
	unsigned int *ptr;
	t_color	c;

	//c.b = (float)y / (float)scene->h;
	c.b = 1.0;
	c.g = 1.0 - ((float)y / (float)scene->h);
	c.r = 1.0 - ((float)y / (float)scene->h);
	ptr = (unsigned int *)data;
	ptr[(int)(x + (y * scene->w))] = color_int(&c);
	
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_scene	scene;
	unsigned int *ptr;
	int bpp, sl, endian;
	t_ray r;
	t_v3f vect;

	float	ratio = 16.0 / 9.0;
	scene.h = 480;
	scene.w = scene.h * ratio;
	
	v3f_clear(&vect);

	ray_clear(&r);
	r.direction.z = -2.0;
	
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, scene.w, scene.h, "minirt");
	mlx_hook(win_ptr, MLX_EVT_DESTROY, 0L, &on_close, (void *)0);

	img_ptr = mlx_new_image(mlx_ptr, scene.w, scene.h);

	ptr = (unsigned int *)mlx_get_data_addr(img_ptr, &(bpp), &(sl), &(endian));

	r.direction.x =  ((20 / (scene.w - 1)) * 2);
	r.direction.y =  ((20 / (scene.h - 1)) * 2);

	v3f_normalize(&r.direction);
	v3f_abs(&r.direction);
	v3f_print(&r.direction);

	scene_around(&scene, ptr, &around);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);	
	mlx_loop(mlx_ptr);

	return (0);
}