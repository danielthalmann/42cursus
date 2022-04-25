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

int		key_down(int keycode, void *param)
{
	t_app	*app;
	app = (t_app *)param;
	(void)keycode;
	app->on_change = 1;
	return (0);
}

int		key_up(int keycode, void *param)
{
	t_app	*app;
	app = (t_app *)param;
	// printf("keycode : %d, %c, %d\n", keycode, keycode, KEY_Q);
	if (keycode == 'q')
		app->mandel.range_min.x += 0.1;
	if (keycode =='w')
		app->mandel.range_min.x -= 0.1;
	if (keycode == 'a')
		app->mandel.zoom += 10;
	if (keycode =='s')
		app->mandel.zoom -= 10;
	if (keycode == 'y')
		app->mandel.max_iter += 10;
	if (keycode =='x')
		app->mandel.max_iter -= 10;
	app->on_change = 1;

	return (0);
}
