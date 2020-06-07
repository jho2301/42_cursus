/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:06:06 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/05 21:15:51 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"




void	sort_sprites (t_sprite *sprites, int num_sprites)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = -1;
	while (++i < num_sprites - 1)
	{
		j = i - 1;
		while (++j < num_sprites)
		{
			if (sprites[i].distance < sprites[j].distance)
			{
				temp = sprites[i];
				sprites[i] = sprites[j];
				sprites[j] = temp;
			}
		}
	}
}


int		get_num_sprites (t_game_info game_info)
{
	int		num_sprites;
	int		j;
	int		k;

	num_sprites = 0;
	j = -1;
	while (++j < game_info.map_height)
	{
		k = -1;
		while (++k < game_info.map_width)
			if (*(*(game_info.map + j) + k) == '2')
				num_sprites++;
	}
	return (num_sprites);
}

void	get_sprites_location(t_game_info g, t_user_view u, t_sprite spr[])
{
	int	i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (++j < g.map_height)
	{
		k = -1;
		while (++k < g.map_width)
		{
			if (g.map[j][k] == '2')
			{
				spr[++i].x = k;
				spr[i].y = j;
				spr[i].distance = ((u.pos_x - spr[i].x) * (u.pos_x - spr[i].x)
								+ (u.pos_y - spr[i].y) * (u.pos_y - spr[i].y));
			}
		}
	}
}

t_sprite_position	get_camera_position(int i, t_sprite sprites[],
								t_user_view u, t_game_info g)
{
	t_sprite_position s;

	s.spriteX = sprites[i].x - u.pos_x;
	s.spriteY = sprites[i].y - u.pos_y;
	s.invDet = 1.0 / (u.plane_x * u.dir_y - u.dir_x * u.plane_y);
	s.transformX = s.invDet * ( u.dir_y * s.spriteX - u.dir_x * s.spriteY);
	s.transformY = s.invDet * (-u.plane_y * s.spriteX + u.plane_x * s.spriteY);
	s.spriteScreenX = (int)((g.res[SCREEN_WIDTH] / 2) * (1 + s.transformX / s.transformY));
	s.spriteHeight = abs((int)(g.res[SCREEN_HEIGHT] / (s.transformY)));
	s.drawStartY = -s.spriteHeight / 2 + g.res[SCREEN_HEIGHT] / 2;
	if (s.drawStartY < 0)
		s.drawStartY = 0;
	s.drawEndY = s.spriteHeight / 2 + g.res[SCREEN_HEIGHT] / 2;
	if (s.drawEndY >=  g.res[SCREEN_HEIGHT])
		s.drawEndY =  g.res[SCREEN_HEIGHT] - 1;
	s.spriteWidth = abs((int) (g.res[SCREEN_HEIGHT] / (s.transformY)));
	s.drawStartX = -s.spriteWidth / 2 + s.spriteScreenX;
	if (s.drawStartX < 0) s.drawStartX = 0;
	s.drawEndX = s.spriteWidth / 2 + s.spriteScreenX;
	if (s.drawEndX >= g.res[SCREEN_WIDTH])
		s.drawEndX = g.res[SCREEN_WIDTH] - 1;
	return (s);
}

void	do_draw_sprites(t_sprite_position spr_pos, t_game_info game_info, t_image *img, double z_buffer[])
{
	for(int x = spr_pos.drawStartX; x < spr_pos.drawEndX; x++)
	{
		int texX = (int)(256 * (x - (-spr_pos.spriteWidth / 2 + spr_pos.spriteScreenX)) * img->width / spr_pos.spriteWidth) / 256;
		if(spr_pos.transformY > 0 && x > 0 && x < game_info.res[SCREEN_WIDTH] && spr_pos.transformY < z_buffer[x])
		for(int y = spr_pos.drawStartY; y < spr_pos.drawEndY; y++) //for every pixel of the current stripe
		{
			int d = (y) * 256 - game_info.res[SCREEN_HEIGHT] * 128 + spr_pos.spriteHeight * 128; //256 and 128 factors to avoid floats
			int texY = ((d * img->height) / spr_pos.spriteHeight) / 256;
			int color = *(img->data + img->width * texY + texX);
			if (color != 0)
				*(img->data + x + game_info.res[SCREEN_WIDTH] * y) = color;
		}
	}
}

void	draw_sprites(void *mlx, t_game_info game_info, t_user_view user_view, double z_buffer[])
{
		int num_sprites;
		t_sprite sprites[get_num_sprites(game_info)];
		t_image sprite_img;
		t_sprite_position spr_pos;

		num_sprites = get_num_sprites(game_info);
		sprite_img.ptr = mlx_xpm_file_to_image(mlx, "./src/run_game/draw/textures/barrel.xpm", &sprite_img.width, &sprite_img.height);
		sprite_img.data = (int *)mlx_get_data_addr(sprite_img.ptr, &sprite_img.bpp, &sprite_img.sizeline, &sprite_img.endian);
		get_sprites_location(game_info, user_view, sprites);
		sort_sprites(sprites, num_sprites);
		for (int i = 0; i < num_sprites; i++)
		{
			spr_pos = get_camera_position(i, sprites, user_view, game_info);
			do_draw_sprites(spr_pos, game_info, &sprite_img, z_buffer);
		}
}
