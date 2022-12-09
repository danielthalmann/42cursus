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

int				mlx_int_find_in_pcm()
{
	return (0);
}

int	on_close(void)
{
	exit(0);
}

void around(t_scene *scene, int x, int y, void *data)
{
//	unsigned int *ptr;
	t_app	*app;
	app = (t_app *)data;
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
	c.b = 1.0 - ((float)y / (float)scene->h);
	c.g = 0.5;
	c.r = 1.0 - ((float)y / (float)scene->h * .5);

//	if (sphere_intersect(&r, &s))
//	{
//		c	.b = 0.5;
//	}

	//int iter = 500;

	app->mandel.x = x;
	app->mandel.y = y;
	// app->mandel.zoom = 200;
	//app->mandel.max_iter = iter;

	m = mandel(&(app->mandel));
	c.b = 1.0 - (m / app->mandel.max_iter);
	c.g = 0.2;
	c.r = 1.0 - (m / 50.0);
	app->pix_ptr[(int)(x + (y * scene->w))] = color_int(&c);
	
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
	
	real = sq(c->r) - sq(c->i);
	imag = 2 * (c->i * c->r);
	c->r = real;
	c->i = imag;
}


// http://sdz.tdct.org/sdz/dessiner-la-fractale-de-mandelbrot.html
int mandel(t_mandel *p)
{
	//t_v2f range_min;
	//t_v3f range_max;
	t_complex z;
	t_complex c;
	float z_r;
	int i;

	//p->range_min.x = -2.1;
	//range_max.x = 0.6;
	//p->range_min.y = -1.1;
	//range_max.y = 1.2;
	c.r = (p->x / p->zoom) + p->range_min.x;
	c.i = (p->y / p->zoom) + p->range_min.y;
	z.r = 0;
	z.i = 0;
	i = 0;

	while (sq(z.r) + sq(z.i) < 4 && i < p->max_iter)
	{
		z_r = z.r;
		z.r = sq(z.r) - sq(z.i) + c.r;
		z.i = 2 * z_r * z.i + c.i;
		i++;
	}
	return (i);
}

int	loop(void *param)
{
	t_app	*app;
	app = (t_app *)param;
	(void)param;

	if (app)
	{
		if (app->on_change)
		{
			int bpp, sl, endian;
			app->img_ptr = mlx_new_image(app->mlx_ptr, app->scene.w, app->scene.h);
			app->pix_ptr = (unsigned int *)mlx_get_data_addr(app->img_ptr, &(bpp), &(sl), &(endian));
			scene_around(&(app->scene), app, &around);
			mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
			app->on_change = 0;

		}
	}

	return (0);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_app	app;
	app.on_change = 1;
	app.mandel.range_min.x = -2.1;
	app.mandel.range_min.y = -1.1;
	app.mandel.zoom = 200;
	app.mandel.max_iter = 500;

	float ratio = 16.0 / 9.0;
	mlx_int_find_in_pcm();
	app.scene.h = 480;
	app.scene.w = app.scene.h * ratio;
	
	app.mlx_ptr = mlx_init();
	if (!app.mlx_ptr)
		return (0);
	app.win_ptr = mlx_new_window(app.mlx_ptr, app.scene.w, app.scene.h, "minirt");
	mlx_hook(app.win_ptr, MLX_EVT_DESTROY, 0L, &on_close, &app);
//	mlx_hook(app.win_ptr, MLX_EVT_KEYDN, 1L, &key_down, &app);
	mlx_hook(app.win_ptr, MLX_EVT_KEYUP, 2L, &key_up, &app);
	mlx_loop_hook(app.mlx_ptr, &loop, &app);


	mlx_loop(app.mlx_ptr);

	return (0);
}