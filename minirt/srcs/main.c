/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:17:13 by dthalman          #+#    #+#             */
/*   Updated: 2022/03/23 08:24:55 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
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
//	t_sphere s;
	t_ray	r;
	int m;

	r.origin.x = 0.0;
	r.origin.y = 0.0;
	r.origin.z = -1.0;

	r.direction.x = -1.0 + (2 * ((float)x / (float)scene->w));
	r.direction.y = -1.0 + (2 * ((float)y / (float)scene->h));
	r.direction.z = 1.0;

	v3f_normalize(&r.direction);

//	s.origin.x = 21.0;
//	s.origin.y = 10.0;
//	s.origin.x = 1.0;
//	s.rayon = 30.0;

	//c.b = (float)y / (float)scene->h;
	c.b = 1.0;
	c.g = 1.0 - ((float)y / (float)scene->h);
	c.r = 1.0 - ((float)y / (float)scene->h);
	ptr = (unsigned int *)data;
//	if (sphere_intersect(&r, &s))
//	{
//		c.b = 0.5;
//	}

	t_complex comp;

	comp.real = (((float)x / (float)scene->w) * 1.2);
	comp.imag = (((float)y / (float)scene->h) * 1.2);

	t_complex z;

	z.real = 0;
	z.imag = 0;

	m = mandel(&comp, &z, 0, 60);
	c.b = m / 60.0;
	ptr[(int)(x + (y * scene->w))] = color_int(&c);
	
}

float	sq(float f)
{
	return f * f;
}

// https://iq.opengenus.org/complex-number-in-c/
// https://www.createursdemondes.fr/programmation/les-fractales-comprendre-et-mettre-en-oeuvre/
void sq_complex(t_complex *c)
{
	float real;
	float imag;
	
	real = sq(c->real) - sq(c->imag);
	imag = 2 * (c->imag * c->real);
	c->real = real;
	c->imag = imag;
}


// http://sdz.tdct.org/sdz/dessiner-la-fractale-de-mandelbrot.html
int	mandel(t_complex *c, t_complex *z, int iter, int iter_max)
{
	sq_complex(z);
	z->real += c->real;
	z->imag += c->imag;
	if ((sq(z->real) + sq(z->imag)) >= 4)
		return (iter);
	if (iter < iter_max)
		return (mandel(c, z, ++iter, iter_max));
	return (iter);
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
	float	ratio = 16.0 / 9.0;

	scene.h = 480;
	scene.w = scene.h * ratio;
	
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, scene.w, scene.h, "minirt");
	mlx_hook(win_ptr, MLX_EVT_DESTROY, 0L, &on_close, (void *)0);
	img_ptr = mlx_new_image(mlx_ptr, scene.w, scene.h);
	ptr = (unsigned int *)mlx_get_data_addr(img_ptr, &(bpp), &(sl), &(endian));

	scene_around(&scene, ptr, &around);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);	
	mlx_loop(mlx_ptr);

	return (0);
}