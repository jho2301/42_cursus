/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:06:06 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/07 21:09:31 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

void	do_draw_sprites(t_spr_pos spr_pos, t_game_info game_info,
						 t_image *tex_img, t_image *img, double z_buffer[])
{
	int	tex_x;
	int	tex_y;
	int	x;
	int	y;
	int	color;

	x = spr_pos.draw_start_x - 1;
	while (++x < spr_pos.draw_end_x)
	{
		tex_x = (int)(256 * (x - (-spr_pos.spr_w / 2 + spr_pos.spr_screen_x))
					* tex_img->w / spr_pos.spr_w) / 256;
		if (spr_pos.trans_y > 0 && x > 0 && x < game_info.res[RES_W_IDX]
										&& spr_pos.trans_y < z_buffer[x])
		{
			y = spr_pos.draw_start_y - 1;
			while (++y < spr_pos.draw_end_y)
			{
				tex_y = (((y * 256 - game_info.res[RES_H_IDX] * 128 +
				spr_pos.spr_h * 128) * tex_img->h) / spr_pos.spr_h) / 256;
				color = *(tex_img->data + tex_img->w * tex_y + tex_x);
				if (color != 0)
					*(img->data + x + game_info.res[RES_W_IDX] * y) = color;
			}
		}
	}
}

void	draw_sprites(void *mlx, t_game_info game_info, t_user_view user_view,
						t_image *img, double z_buffer[])
{
		int			num_sprites;
		t_image		spr_img;
		t_sprite	**sprs;
		t_spr_pos	spr_pos;

		num_sprites = get_num_sprites(game_info);
		sprs = malloc(sizeof(t_sprite *) * num_sprites);
		for (int i = 0; i < num_sprites; i++)
			*(sprs + i) = malloc(sizeof(t_sprite));
		load_texture(mlx, game_info.sprite, &spr_img);
		get_sprites_location(game_info, user_view, sprs);
		sort_sprites(sprs, num_sprites);
		for (int i = 0; i < num_sprites; i++)
		{
			spr_pos = get_camera_position(i, sprs, user_view, game_info);
			do_draw_sprites(spr_pos, game_info, &spr_img, img, z_buffer);
		}
		for (int i = 0; i < num_sprites; i++)
			free(*(sprs + i));
		free(sprs);
		mlx_destroy_image(mlx, spr_img.ptr);
}
