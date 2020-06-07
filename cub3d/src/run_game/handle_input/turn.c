/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:34:39 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/05 21:07:52 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

void	turn_right(t_user_view *u)
{
	double oldDirX = u->dir_x;
	double oldPlaneX = u->plane_x;

	u->dir_x = u->dir_x * cos(1) - u->dir_y * sin(1);
	u->dir_y  = oldDirX * sin(1) + u->dir_y * cos(1);
	u->plane_x = u->plane_x * cos(1) - u->plane_y * sin(1);
	u->plane_y = oldPlaneX * sin(1) + u->plane_y * cos(1);
}

void	turn_left(t_user_view *u)
{
	double oldDirX = u->dir_x;
	double oldPlaneX = u->plane_x;

	u->dir_x = u->dir_x * cos(-1) - u->dir_y * sin(-1);
	u->dir_y = oldDirX * sin(-1) + u->dir_y * cos(-1);
	u->plane_x = u->plane_x * cos(-1) - u->plane_y * sin(-1);
	u->plane_y = oldPlaneX * sin(-1) + u->plane_y * cos(-1);
}
