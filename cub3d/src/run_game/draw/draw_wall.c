/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:21:49 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/05 21:52:01 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

void	load_texture_img(void *mlx, t_image *texture, t_dda dda)
{
	if (dda.side == 0 && dda.rayDirX < 0)
		texture->ptr = mlx_xpm_file_to_image(mlx, "./src/run_game/draw/textures/wood.xpm", &texture->width, &texture->height);
	else if (dda.side == 0)
		texture->ptr = mlx_xpm_file_to_image(mlx, "./src/run_game/draw/textures/redbrick.xpm", &texture->width, &texture->height);
	else if (dda.rayDirY < 0)
		texture->ptr = mlx_xpm_file_to_image(mlx, "./src/run_game/draw/textures/mossy.xpm", &texture->width, &texture->height);
	else
		texture->ptr = mlx_xpm_file_to_image(mlx, "./src/run_game/draw/textures/colorstone.xpm", &texture->width, &texture->height);
	texture->data = (int *)mlx_get_data_addr(texture->ptr, &texture->bpp, &texture->sizeline, &texture->endian);
}

void	do_draw_wall(t_image img, t_texture tex_val, t_image tex_img, t_game_info *game_info, t_dda dda)
{
	int color;
	int y;

	y = dda.drawStart;
	while (y < dda.drawEnd)
	{
		tex_val.texY = (int)tex_val.texPos & (tex_img.height - 1);
		tex_val.texPos += tex_val.step;
		if (tex_val.texX < 0 || tex_val.texY < 0)
		color = *(tex_img.data + (tex_img.width * tex_val.texY) + tex_val.texX);
		*(img.data + (game_info->res[SCREEN_WIDTH] * y) + dda.x) = 1;
		y++;
	}

}

void draw_wall(void *mlx, t_user_view user_view, t_game_info *game_info, t_image img, t_dda dda)
{
	t_image		tex_img;
	t_texture	tex_val;

	load_texture_img(mlx, &tex_img, dda);
	///////////////////////////////////////////
	tex_val.wallX = dda.side == 0 ? user_view.pos_x + dda.perpWallDist * dda.rayDirY : user_view.pos_x + dda.perpWallDist * dda.rayDirX;
	///////////////////////////////////////////
	tex_val.wallX -= (int)tex_val.wallX;
	tex_val.texX = (int)(tex_val.wallX * tex_img.width);
	if (dda.side == 0 && dda.rayDirX > 0)
		tex_val.texX = tex_img.width - tex_val.texX - 1;
	if (dda.side == 1 && dda.rayDirY < 0)
		tex_val.texX = tex_img.width - tex_val.texX - 1;
	tex_val.step = 1.0 * tex_img.height / dda.lineHeight;
	tex_val.texPos = (dda.drawStart - game_info->res[SCREEN_HEIGHT] / 2 + dda.lineHeight / 2) * tex_val.step;
	do_draw_wall(img, tex_val, tex_img, game_info, dda);
	mlx_destroy_image (mlx, tex_img.ptr);
}
