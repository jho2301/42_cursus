/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:35:02 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/05 20:24:16 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

t_bool	check_move(char map_value)
{
	if (map_value == '0' ||
		map_value == 'N'||
		map_value == 'S'||
		map_value == 'W'||
		map_value == 'E')
		return (TRUE);
	return (FALSE);
}

void	move_forward(t_game_info g, t_user_view *u)
{
	double p_x;
	double p_y;
	double d_x;
	double d_y;

	p_x = u->pos_x;
	p_y = u->pos_y;
	d_x = u->dir_x;
	d_y = u->dir_y;
	if (0 < (int)(p_y + d_y) && check_move(*(*(g.map + (int)(p_y + d_y)) + (int)p_x)))
		u->pos_y += u->dir_y;
	if (0 < (int)(p_x + d_x) && check_move(*(*(g.map + (int)p_y) + (int)(p_x + d_x))))
		u->pos_x += u->dir_x;
}

void	move_backward(t_game_info g, t_user_view *u)
{
	double p_x;
	double p_y;
	double d_x;
	double d_y;

	p_x = u->pos_x;
	p_y = u->pos_y;
	d_x = u->dir_x;
	d_y = u->dir_y;
	if (0 < (int)(p_y - d_y) && check_move(*(*(g.map + (int)(p_y - d_y)) + (int)p_x)))
		u->pos_y -= u->dir_y;
	if (0 < (int)(p_x - d_x) && check_move(*(*(g.map + (int)p_y) + (int)(p_x - d_x))))
		u->pos_x -= u->dir_x;
}

void	move_rightward(t_game_info g, t_user_view *u)
{
	double p_x;
	double p_y;
	double d_x;
	double d_y;

	p_x = u->pos_x;
	p_y = u->pos_y;
	d_x = u->dir_x;
	d_y = u->dir_y;
	if (0 < (int)(p_y + d_x) && check_move(*(*(g.map + (int)(p_y + d_x)) + (int)p_x)))
		u->pos_y += u->dir_x;
	if (0 < (int)(p_x - d_y) && check_move(*(*(g.map + (int)p_y) + (int)(p_x - d_y))))
		u->pos_x -= u->dir_y;
}

void	move_leftward(t_game_info g, t_user_view *u)
{
	double p_x;
	double p_y;
	double d_x;
	double d_y;

	p_x = u->pos_x;
	p_y = u->pos_y;
	d_x = u->dir_x;
	d_y = u->dir_y;
		if (0 < (int)(p_y - d_x) && check_move(*(*(g.map + (int)(p_y - d_x)) + (int)p_x)))
			u->pos_y -= u->dir_x;
		if (0 < (int)(p_x + d_y) && check_move(*(*(g.map + (int)p_y) + (int)(p_x + d_y))))
			u->pos_x += u->dir_y;
}
