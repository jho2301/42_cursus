/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:15:53 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/05 20:34:20 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

void	set_user_info_dir_plane(t_user_view *user_view,
								double dir_x,
								double dir_y,
								double plane_x,
								double plane_y)
{
	user_view->dir_x = dir_x;
	user_view->dir_y = dir_y;
	user_view->plane_x = plane_x;
	user_view->plane_y = plane_y;
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
					set_user_info_dir_plane(user_view, 0, -1, 0.6, 0);
				else if (game_info->map[y][x] == 'S')
					set_user_info_dir_plane(user_view, 0, 1, -0.6, 0);
				else if (game_info->map[y][x] == 'W')
					set_user_info_dir_plane(user_view, 1, 0, 0, 0.6);
				else if (game_info->map[y][x] == 'E')
					set_user_info_dir_plane(user_view, -1, 0, 0, -0.6);
			 }
		}
	}
}
