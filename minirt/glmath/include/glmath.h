/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glmath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:40:24 by dthalman          #+#    #+#             */
/*   Updated: 2022/03/23 07:55:28 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLMATH_H
# define GLMATH_H
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef float				t_c;
typedef struct s_vector4f
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_v4f;

typedef struct s_vector4f	t_v3f;
typedef struct s_vector4f	t_point3f;

typedef struct s_vector2f
{
	float	x;
	float	y;
}	t_v2f;

typedef struct s_point2
{
	int	x;
	int	y;
}	t_point;
typedef struct s_point2f
{
	float	x;
	float	y;
}	t_pointf;
typedef struct s_color
{
	t_c	r;
	t_c	g;
	t_c	b;
	t_c	a;
}	t_color;
typedef struct s_ray
{
	t_point3f	origin;
	t_v3f		direction;
}	t_ray;
typedef struct s_size
{
	int	w;
	int	h;
}	t_size;

typedef struct s_size		t_scene;

t_v3f	*v3f_create(t_v3f *copy);
void	v3f_add(t_v3f *to, t_v3f *add);
void	v3f_sub(t_v3f *to, t_v3f *sub);
void	v3f_normalize(t_v3f *vector);
void	v3f_multi(t_v3f *vector, t_v3f *multi);
void	v3f_multi_v(t_v3f *vector, float value);
void	v3f_clear(t_v3f *vector);
void	v3f_copy(t_v3f *to, t_v3f *copy);
void	v3f_abs(t_v3f *vector);
void	v3f_print(t_v3f *vector);

t_color	*color_create(t_color *copy);
t_color	*color_create_int(int color);
int		color_int(t_color *color);
void	cpy_vector_to_color(t_color *color, t_v3f *v);

t_ray	*ray_create(t_ray *copy);
t_v3f	*ray_at(float pos, t_ray *ray);
void	ray_clear(t_ray *r);

void	scene_around(t_scene *scene, void *data,
			void (*fn)(t_scene *, int, int, void *));

/* sphere */
typedef struct s_sphere
{
	t_point3f	origin;
	float		rayon;
}	t_sphere;

int		sphere_intersect(t_ray *ray, t_sphere *sphere);
void	computeColorNormal(t_ray *ray, float dist, t_color *c, t_v3f *normal);

#endif
