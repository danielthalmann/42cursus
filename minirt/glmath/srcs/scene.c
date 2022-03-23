/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 09:55:20 by dthalman          #+#    #+#             */
/*   Updated: 2022/03/20 10:40:25 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glmath.h"

void	scene_around(t_scene *scene, void *data,
		void (*fn)(t_scene *, int, int, void *))
{
	t_point	pos;

	pos.y = 0;
	while (pos.y < scene->h)
	{
		pos.x = 0;
		while (pos.x < scene->w)
		{
			fn(scene, pos.x, pos.y, data);
			pos.x++;
		}
		pos.y++;
	}
}
