/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmathgraphic.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:40:24 by dthalman          #+#    #+#             */
/*   Updated: 2022/02/28 10:40:24 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATHGRAPHIC_H
# define LIBMATHGRAPHIC_H
# include <stdlib.h>
# include <math.h>
typedef char t_onecolor;
typedef struct s_vector3f
{
	float	x;
	float	y;
	float	z;
}	t_vector3f;
typedef struct s_point2f
{
	float	x;
	float	y;
}	t_pointf;
typedef struct s_color
{
	t_onecolor	r;
	t_onecolor	g;
	t_onecolor	b;
}	t_color;
t_vector3f	*v3f_create(t_vector3f *copy);
void		v3f_add(t_vector3f *to, t_vector3f *add);
void		v3f_sub(t_vector3f *to, t_vector3f *sub);

#endif
