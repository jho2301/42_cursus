/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:21:49 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/07 21:11:30 by hjeon            ###   ########.fr       */
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

void	do_draw_wall(t_image img, t_texture tex_val, t_image tex_img,
								 t_game_info *game_info, t_dda dda)
{
	int val;
	int y;

	y = dda.draw_start;
	while (y < dda.draw_end)
	{
		tex_val.tex_y = (int)tex_val.tex_pos & (tex_img.h - 1);
		tex_val.tex_pos += tex_val.step;
		val = *(tex_img.data + (tex_img.w * tex_val.tex_y) + tex_val.tex_x);
		if (tex_val.tex_x >= 0 && tex_val.tex_y >= 0)
			*(img.data + (game_info->res[RES_W_IDX] * y) + dda.x) = val;
		y++;
	}

}

void draw_wall(void *mlx, t_user_view user_view, t_game_info *game_info,
												 t_image img, t_dda dda)
{
	t_image		tex_img;
	t_texture	tex_val;

	load_texture_img(mlx, *game_info, &tex_img, dda);
	tex_val.wall_x = dda.side == 0 ? user_view.pos_x + dda.perpwalldist
													* dda.raydir_y
									: user_view.pos_x + dda.perpwalldist
													 * dda.raydir_x;
	tex_val.wall_x -= (int)tex_val.wall_x;
	tex_val.tex_x = (int)(tex_val.wall_x * tex_img.w);
	if (dda.side == 0 && dda.raydir_x > 0)
		tex_val.tex_x = tex_img.w - tex_val.tex_x - 1;
	if (dda.side == 1 && dda.raydir_y < 0)
		tex_val.tex_x = tex_img.w - tex_val.tex_x - 1;
	tex_val.tex_x = tex_val.tex_x < 0 ? 0 : tex_val.tex_x;
	tex_val.step = 1.0 * tex_img.h / dda.line_h;
	tex_val.tex_pos = (dda.draw_start - game_info->res[RES_H_IDX] / 2
										+ dda.line_h / 2) * tex_val.step;
	do_draw_wall(img, tex_val, tex_img, game_info, dda);
	mlx_destroy_image (mlx, tex_img.ptr);
}
