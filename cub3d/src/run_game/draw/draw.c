/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:13:57 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/08 11:38:55 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_is_updated = 0;

#include "../run_game.h"

void	do_draw(void *ptrs[], t_game_info *game_info,
				t_user_view user_view, t_bool screenshot)
{
	t_image		img;
	t_dda		dda;
	double		z_buffer[game_info->res[RES_W_IDX]];

	img.ptr = mlx_new_image(ptrs[0], game_info->res[RES_W_IDX],
							 game_info->res[RES_H_IDX]);
	img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp,
										&img.sizeline, &img.endian);
	draw_floor_ceiling(game_info, ptrs[0], &img);
	for(int x = 0; x < game_info->res[RES_W_IDX]; x++)
	{
		dda = raycast(game_info, user_view, z_buffer, x);
		draw_wall(ptrs[0], user_view, game_info,
					(void *[]){(void *)&img, (void *)&dda});
	}
	draw_sprites((void*[]){ptrs[0], (void *)&img},
				*game_info, user_view, z_buffer);
	if (screenshot == TRUE)
		take_screenshot(&img, game_info);
	mlx_put_image_to_window(ptrs[0], ptrs[1], img.ptr, 0, 0);
	mlx_destroy_image(ptrs[0], img.ptr);
}

int		draw(void **infos)
{
	t_user_view		user_view;
	t_game_info		*game_info;
	void			*mlx;
	void			*window;
	t_bool			screenshot;

	user_view = *(t_user_view *)infos[0];
	game_info = (t_game_info *)infos[1];
	mlx = infos[2];
	window = infos[3];
	screenshot = *(int *)infos[4];
	if (!g_is_updated)
	{
		do_draw((void *[]){mlx, window}, game_info, user_view, screenshot);
		g_is_updated = TRUE;
	}
	return (0);
}
