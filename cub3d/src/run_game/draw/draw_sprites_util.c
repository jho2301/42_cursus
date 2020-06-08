/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 20:23:57 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/08 13:37:03 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

void		sort_sprites(t_sprite *sprites[], int num_sprites)
{
	int			i;
	int			j;
	t_sprite	*temp;

	i = -1;
	while (++i < num_sprites - 1)
	{
		j = i - 1;
		while (++j < num_sprites)
		{
			if (sprites[i]->dist < sprites[j]->dist)
			{
				temp = sprites[i];
				sprites[i] = sprites[j];
				sprites[j] = temp;
			}
		}
	}
}

int			get_num_sprites(t_game_info game_info)
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

void		get_sprites_location(t_game_info g, t_user_view u, t_sprite **spr)
{
	int	i;
	int j;
	int k;

	i = -1;
	j = -1;
	while (++j < g.map_height)
	{
		k = -1;
		while (++k < g.map_width)
		{
			if (g.map[j][k] == '2')
			{
				spr[++i]->x = k;
				spr[i]->y = j;
				spr[i]->dist = ((u.pos_x - spr[i]->x)
								* (u.pos_x - spr[i]->x)
								+ (u.pos_y - spr[i]->y)
								* (u.pos_y - spr[i]->y));
			}
		}
	}
}

t_spr_pos	get_camera_position(int i, t_sprite *sprites[],
								t_user_view u, t_game_info g)
{
	t_spr_pos s;

	s.spr_x = sprites[i]->x - u.pos_x + 0.5;
	s.spr_y = sprites[i]->y - u.pos_y + 0.5;
	s.inv_det = 1.0 / (u.plane_x * u.dir_y - u.dir_x * u.plane_y);
	s.trans_x = s.inv_det * (u.dir_y * s.spr_x - u.dir_x * s.spr_y);
	s.trans_y = s.inv_det * (-u.plane_y * s.spr_x + u.plane_x * s.spr_y);
	s.spr_screen_x = (int)((g.res[RES_W_IDX] / 2)
						* (1 + s.trans_x / s.trans_y));
	s.spr_h = abs((int)(g.res[RES_H_IDX] / (s.trans_y)));
	s.draw_start_y = -s.spr_h / 2 + g.res[RES_H_IDX] / 2;
	if (s.draw_start_y < 0)
		s.draw_start_y = 0;
	s.draw_end_y = s.spr_h / 2 + g.res[RES_H_IDX] / 2;
	if (s.draw_end_y >= g.res[RES_H_IDX])
		s.draw_end_y = g.res[RES_H_IDX] - 1;
	s.spr_w = abs((int)(g.res[RES_H_IDX] / (s.trans_y)));
	s.draw_start_x = -s.spr_w / 2 + s.spr_screen_x;
	if (s.draw_start_x < 0)
		s.draw_start_x = 0;
	s.draw_end_x = s.spr_w / 2 + s.spr_screen_x;
	if (s.draw_end_x >= g.res[RES_W_IDX])
		s.draw_end_x = g.res[RES_W_IDX] - 1;
	return (s);
}
