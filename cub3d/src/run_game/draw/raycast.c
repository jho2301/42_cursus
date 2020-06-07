/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 21:09:53 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/07 21:15:04 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

void	set_step_side_dist(t_user_view u, t_dda *dda)
{
	if (dda->raydir_x < 0)
	{
		dda->step_x = -1;
		dda->sidedist_x = (u.pos_x - dda->map_x) * dda->deltadist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->sidedist_x = (dda->map_x + 1.0 - u.pos_x) * dda->deltadist_x;
	}
	if (dda->raydir_y < 0)
	{
		dda->step_y = -1;
		dda->sidedist_y = (u.pos_y - dda->map_y) * dda->deltadist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->sidedist_y = (dda->map_y + 1.0 - u.pos_y) * dda->deltadist_y;
	}
}

void	init_dda(t_game_info *game_info, t_user_view user_view, t_dda *dda)
{
	dda->cam_x = 2 * dda->x / (double)game_info->res[RES_W_IDX] - 1;
	dda->raydir_x = user_view.dir_x + user_view.plane_x * dda->cam_x;
	dda->raydir_y = user_view.dir_y + user_view.plane_y * dda->cam_x;
	dda->map_x = (int)user_view.pos_x;
	dda->map_y = (int)user_view.pos_y;
	dda->deltadist_x = 1 / dda->raydir_x;
	dda->deltadist_x = dda->deltadist_x > 0 ? dda->deltadist_x
											: dda->deltadist_x * -1;
	dda->deltadist_y = 1 / dda->raydir_y;
	dda->deltadist_y = dda->deltadist_y > 0 ? dda->deltadist_y
											: dda->deltadist_y * -1;
	dda->hit = 0;
	set_step_side_dist(user_view, dda);
}

void	do_dda(t_game_info *game_info, t_user_view u, t_dda *dda)
{
	while (dda->hit == 0)
	{
		if(dda->sidedist_x < dda->sidedist_y)
		{
			dda->sidedist_x += dda->deltadist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->sidedist_y += dda->deltadist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (*(*(game_info->map + dda->map_y) + dda->map_x) == '1')
			dda->hit = 1;
	}
	if (dda->side == 0)
		dda->perpwalldist = (dda->map_x - u.pos_x + (1 - dda->step_x) / 2)
															 / dda->raydir_x;
	else
		dda->perpwalldist = (dda->map_y - u.pos_y + (1 - dda->step_y) / 2)
															/ dda->raydir_y;
}

void	get_dda_draw_data(t_game_info *game_info, t_dda *dda)
{
	dda->line_h = (int)(game_info->res[RES_H_IDX] / dda->perpwalldist);
	dda->draw_start = -dda->line_h / 2 + game_info->res[RES_H_IDX] / 2;
	if(dda->draw_start < 0)
		dda->draw_start = 0;
	dda->draw_end = (dda->line_h / 2) + (game_info->res[RES_H_IDX] / 2);
	if(dda->draw_end >= game_info->res[RES_H_IDX])
		dda->draw_end = game_info->res[RES_H_IDX] - 1;
}

t_dda	raycast(t_game_info *g, t_user_view u, double z_buffer[], int x)
{
	t_dda dda;

	dda.x = x;
	init_dda(g, u, &dda);
	do_dda(g, u, &dda);
	z_buffer[dda.x] = dda.perpwalldist;
	get_dda_draw_data(g, &dda);
	return (dda);
}
