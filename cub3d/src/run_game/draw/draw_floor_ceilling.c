/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceilling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:17:25 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/04 18:15:09 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

void	draw_floor_ceiling(t_game_info *game_info, void *mlx_ptr, t_image *img)
{
	int		floor_color;
	int		ceilling_color;
	int		w;
	int		h;

	floor_color = game_info->floor[2] + game_info->floor[1] * 256
									 + game_info->floor[0] * 256 * 256;
	ceilling_color = game_info->ceilling[2] + game_info->ceilling[1] * 256
										+ game_info->ceilling[0] * 256 * 256;
	w = -1;
	while (++w < game_info->res[SCREEN_WIDTH])
	{
		h = -1;
		while (++h < game_info->res[SCREEN_HEIGHT] / 2)
			*(img->data + (game_info->res[SCREEN_WIDTH] * h) + w) =
								mlx_get_color_value(mlx_ptr, ceilling_color);
	}
	w = -1;
	while (++w < game_info->res[SCREEN_WIDTH])
	{
		h = game_info->res[SCREEN_HEIGHT] / 2;
		while (++h < game_info->res[SCREEN_HEIGHT])
			*(img->data + (game_info->res[SCREEN_WIDTH] * h) + w) =
								mlx_get_color_value(mlx_ptr, floor_color);
	}
}
