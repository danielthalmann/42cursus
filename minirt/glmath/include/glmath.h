/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glmath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:40:24 by dthalman          #+#    #+#             */
/*   Updated: 2022/03/05 08:59:48 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGLMATH_H
# define LIBGLMATH_H
# include <stdlib.h>
# include <math.h>

typedef int	t_c;
typedef struct s_vector3f
{
	float	x;
	float	y;
	float	z;
}	t_v3f;
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
t_v3f	*v3f_create(t_v3f *copy);
void	v3f_add(t_v3f *to, t_v3f *add);
void	v3f_sub(t_v3f *to, t_v3f *sub);
void	v3f_normalize(t_v3f *vector);
void	v3f_multi(t_v3f *vector, t_v3f *multi);
void	v3f_multi_v(t_v3f *vector, float value);
t_color	*color_create(t_color *copy);
t_color	*color_create_int(int color);
int		color_int(t_color *color);
#endif
