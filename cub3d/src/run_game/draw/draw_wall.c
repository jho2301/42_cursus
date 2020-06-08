/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:21:49 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/08 13:39:52 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

void	load_texture_img(void *mlx, t_game_info game_info,
							t_image *texture, t_dda dda)
{
	if (dda.side == 0 && dda.raydir_x < 0)
		load_texture(mlx, game_info.west, texture);
	else if (dda.side == 0)
		load_texture(mlx, game_info.east, texture);
	else if (dda.raydir_y < 0)
		load_texture(mlx, game_info.north, texture);
	else
		load_texture(mlx, game_info.south, texture);
}

void	do_draw_wall(t_image imgs[], t_texture tex_val,
					t_game_info *game_info, t_dda dda)
{
	int val;
	int y;

	y = dda.draw_start;
	while (y < dda.draw_end)
	{
		tex_val.tex_y = (int)tex_val.tex_pos & (imgs[1].h - 1);
		tex_val.tex_pos += tex_val.step;
		val = *(imgs[1].data + (imgs[1].w * tex_val.tex_y) + tex_val.tex_x);
		if (tex_val.tex_x >= 0 && tex_val.tex_y >= 0)
			*(imgs[0].data + (game_info->res[RES_W_IDX] * y) + dda.x) = val;
		y++;
	}
}

void	draw_wall(void *mlx, t_user_view user_view, t_game_info *game_info,
													void *vals[])
{
	t_image		tex_img;
	t_texture	tex_val;

	load_texture_img(mlx, *game_info, &tex_img, *(t_dda *)vals[1]);
	tex_val.wall_x = ((t_dda *)vals[1])->side == 0 ? user_view.pos_x
			+ ((t_dda *)vals[1])->perpwalldist * ((t_dda *)vals[1])->raydir_y
				: user_view.pos_x + ((t_dda *)vals[1])->perpwalldist
												* ((t_dda *)vals[1])->raydir_x;
	tex_val.wall_x -= (int)tex_val.wall_x;
	tex_val.tex_x = (int)(tex_val.wall_x * tex_img.w);
	if (((t_dda *)vals[1])->side == 0 && ((t_dda *)vals[1])->raydir_x > 0)
		tex_val.tex_x = tex_img.w - tex_val.tex_x - 1;
	if (((t_dda *)vals[1])->side == 1 && ((t_dda *)vals[1])->raydir_y < 0)
		tex_val.tex_x = tex_img.w - tex_val.tex_x - 1;
	tex_val.tex_x = tex_val.tex_x < 0 ? 0 : tex_val.tex_x;
	tex_val.step = 1.0 * tex_img.h / ((t_dda *)vals[1])->line_h;
	tex_val.tex_pos = (((t_dda *)vals[1])->draw_start
					- game_info->res[RES_H_IDX] / 2
					+ ((t_dda *)vals[1])->line_h / 2) * tex_val.step;
	do_draw_wall((t_image[]){*(t_image*)vals[0], tex_img},
					tex_val, game_info, *(t_dda *)vals[1]);
	mlx_destroy_image(mlx, tex_img.ptr);
}
