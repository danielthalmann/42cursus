/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthalman <daniel@thalmann.li>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:23:55 by dthalman          #+#    #+#             */
/*   Updated: 2021/11/21 03:29:46 by dthalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "libft.h"

typedef unsigned int	t_uint;
typedef struct s_state
{
	int	on_walk;
	int	on_stay;
}	t_state;
typedef struct s_position
{
	t_uint	x;
	t_uint	y;
}	t_pos;
typedef struct s_size
{
	t_uint	w;
	t_uint	h;
}	t_size;
typedef struct s_gl
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_gl;
typedef struct s_map
{
	t_size	size;
	t_uint	*coord;
	t_pos	player_pos;
	t_pos	exit;
	t_list	*coll;
	void	*img_ptr;
}	t_map;
typedef struct s_player
{
	int		state;
	t_pos	position;
	t_pos	map_position;
	void	*img_ptr;
	int		speed_anim;
	int		anim_last_time;
	int		anim_index;
	int		speed;
	int		speed_last_time;
	int		anim_limit[10];
	int		walk;
	t_pos	destination;
	t_pos	map_destination;
}	t_player;
typedef struct s_game
{
	int			is_init;
	t_gl		gl;
	t_map		map;
	t_player	player;
}	t_game;
int	ft_compare_pos(t_pos *a, t_pos *b);
#endif
