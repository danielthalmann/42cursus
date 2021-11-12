/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:23:55 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/12 15:00:57 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define SWAP_INT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24)) 

typedef unsigned int	t_uint;
typedef struct s_position
{
	t_uint	x;
	t_uint	y;
}	t_position;
typedef struct s_size
{
	t_uint	width;
	t_uint	height;
}	t_size;
typedef struct s_gl
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_gl;
#endif