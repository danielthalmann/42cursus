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
#include "mlx.h"
#include "glmath.h"

typedef struct s_complex
{
	float	real;
	float	imag;
}	t_complex;

float	sq(float f);
void 	around(t_scene *scene, int x, int y, void *data);
void 	sq_complex(t_complex *c);
int		mandel(t_complex *c, t_complex *z, int iter, int iter_max);

#endif