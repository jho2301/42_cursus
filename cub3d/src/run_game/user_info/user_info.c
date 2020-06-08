/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:15:53 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/08 13:19:30 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

void	set_dp(t_user_view *user_view, double dir[], double plane[])
{
	user_view->dir_x = dir[0];
	user_view->dir_y = dir[1];
	user_view->plane_x = plane[0];
	user_view->plane_y = plane[1];
}

void	get_user_info(t_game_info *game_info, t_user_view *user_view)
{
	int		x;
	int		y;

	y = -1;
	while (++y < game_info->map_height)
	{
		x = -1;
		while (++x < game_info->map_width)
		{
			if (game_info->map[y][x] == 'N' || game_info->map[y][x] == 'S' ||
					game_info->map[y][x] == 'W' || game_info->map[y][x] == 'E')
			{
				user_view->pos_x = x + 0.5;
				user_view->pos_y = y + 0.5;
				if (game_info->map[y][x] == 'N')
					set_dp(user_view, (double[]){0, -1}, (double[]){0.6, 0});
				else if (game_info->map[y][x] == 'S')
					set_dp(user_view, (double[]){0, 1}, (double[]){-0.6, 0});
				else if (game_info->map[y][x] == 'W')
					set_dp(user_view, (double[]){1, 0}, (double[]){0, 0.6});
				else if (game_info->map[y][x] == 'E')
					set_dp(user_view, (double[]){-1, 0}, (double[]){0, -0.6});
			}
		}
	}
}
