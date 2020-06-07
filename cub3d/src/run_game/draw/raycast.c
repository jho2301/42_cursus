/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 21:09:53 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/05 19:16:04 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

void	set_step_side_dist(t_user_view user_view, t_dda *dda)
{
	if (dda->rayDirX < 0)
	{
		dda->stepX = -1;
		dda->sideDistX = (user_view.pos_x - dda->mapX) * dda->deltaDistX;
	}
	else
	{
		dda->stepX = 1;
		dda->sideDistX = (dda->mapX + 1.0 - user_view.pos_x) * dda->deltaDistX;
	}
	if (dda->rayDirY < 0)
	{
		dda->stepY = -1;
		dda->sideDistY = (user_view.pos_y - dda->mapY) * dda->deltaDistY;
	}
	else
	{
		dda->stepY = 1;
		dda->sideDistY = (dda->mapY + 1.0 - user_view.pos_y) * dda->deltaDistY;
	}
}

void	init_dda(t_game_info *game_info, t_user_view user_view, t_dda *dda)
{
	dda->cameraX = 2 * dda->x / (double)game_info->res[SCREEN_WIDTH] - 1;
	dda->rayDirX = user_view.dir_x + user_view.plane_x * dda->cameraX;
	dda->rayDirY = user_view.dir_y + user_view.plane_y * dda->cameraX;
	dda->mapX = (int)user_view.pos_x;
	dda->mapY = (int)user_view.pos_y;
	dda->deltaDistX = 1 / dda->rayDirX;
	dda->deltaDistX = dda->deltaDistX > 0 ? dda->deltaDistX : dda->deltaDistX * -1;
	dda->deltaDistY = 1 / dda->rayDirY;
	dda->deltaDistY = dda->deltaDistY > 0 ? dda->deltaDistY : dda->deltaDistY * -1;
	dda->hit = 0;
	set_step_side_dist(user_view, dda);
}

void	do_dda(t_game_info *game_info, t_user_view user_view, t_dda *dda)
{
	while (dda->hit == 0)
	{
		if(dda->sideDistX < dda->sideDistY)
		{
			dda->sideDistX += dda->deltaDistX;
			dda->mapX += dda->stepX;
			dda->side = 0;
		}
		else
		{
			dda->sideDistY += dda->deltaDistY;
			dda->mapY += dda->stepY;
			dda->side = 1;
		}
		if (*(*(game_info->map + dda->mapY) + dda->mapX) == '1')
			dda->hit = 1;
	}
	if (dda->side == 0)
		dda->perpWallDist = (dda->mapX - user_view.pos_x + (1 - dda->stepX) / 2) / dda->rayDirX;
	else
		dda->perpWallDist = (dda->mapY - user_view.pos_y + (1 - dda->stepY) / 2) / dda->rayDirY;
}

void	get_dda_draw_data(t_game_info *game_info, t_dda *dda)
{
	dda->lineHeight = (int)(game_info->res[SCREEN_HEIGHT] / dda->perpWallDist);
	dda->drawStart = -dda->lineHeight / 2 + game_info->res[SCREEN_HEIGHT] / 2;
	if(dda->drawStart < 0)
		dda->drawStart = 0;
	dda->drawEnd = (dda->lineHeight / 2) + (game_info->res[SCREEN_HEIGHT] / 2);
	if(dda->drawEnd >= game_info->res[SCREEN_HEIGHT])
		dda->drawEnd = game_info->res[SCREEN_HEIGHT] - 1;
}

t_dda	raycast(t_game_info *game_info, t_user_view user_view, double ZBuffer[], int x)
{
	t_dda dda;

	dda.x = x;
	init_dda(game_info, user_view, &dda);
	do_dda(game_info, user_view, &dda);
	ZBuffer[dda.x] = dda.perpWallDist;
	get_dda_draw_data(game_info, &dda);
	return (dda);
}
