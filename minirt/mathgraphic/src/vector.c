/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:42:10 by dthalman          #+#    #+#             */
/*   Updated: 2022/02/28 10:42:10 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathgraphic.h"

t_vector3f	*v3f_create(t_vector3f *copy)
{
	t_vector3f	*v;

	v = malloc(sizeof(t_vector3f));
	if (copy != NULL)
	{
		v->x = copy->x;
		v->y = copy->y;
		v->z = copy->z;
	}
	else
	{
		v->x = 0;
		v->y = 0;
		v->z = 0;
	}
	return (v);
}

void	v3f_add(t_vector3f *to, t_vector3f *add)
{
	to->x += add->x;
	to->y += add->y;
	to->z += add->z;
}

void	v3f_sub(t_vector3f *to, t_vector3f *sub)
{
	to->x -= sub->x;
	to->y -= sub->y;
	to->z -= sub->z;
}