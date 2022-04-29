/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:03:04 by dthalman          #+#    #+#             */
/*   Updated: 2022/04/01 13:03:04 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "glmath.h"
#include "input.h"

# define MLX_EVT_KEYDN 2
# define MLX_EVT_KEYUP 3
# define MLX_EVT_DESTROY 17

typedef struct s_complex
{
	float	r;
	float	i;
}	t_complex;
// 

typedef struct s_mandel
{
	int x;
	int y;
	float zoom;
	t_v2f range_min;
	int max_iter;
}	t_mandel;
typedef struct s_app
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				on_change;
	unsigned int	*pix_ptr;
	t_mandel		mandel;
	t_scene			scene;
}	t_app;

float	sq(float f);
void 	around(t_scene *scene, int x, int y, void *data);
void 	sq_complex(t_complex *c);
int		mandel(t_mandel *params);

#endif