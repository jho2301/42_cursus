/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:13:57 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/05 21:16:34 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

int		is_updated = FALSE;

void	do_draw(void *mlx, void *window, t_game_info *game_info,
				t_user_view user_view, t_bool screenshot)
{
	t_image		img;
	t_dda		dda;
	double		z_buffer[game_info->res[SCREEN_WIDTH]];

	img.ptr = mlx_new_image(mlx, game_info->res[SCREEN_WIDTH],
							 game_info->res[SCREEN_HEIGHT]);
	img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp,
										&img.sizeline, &img.endian);
	draw_floor_ceiling(game_info, mlx, &img);
	for(int x = 0; x < game_info->res[SCREEN_WIDTH]; x++)
	{
		dda = raycast(game_info, user_view, z_buffer, x);
		draw_wall(mlx, user_view, game_info, img, dda);
	}
	// draw_sprites(mlx, *game_info, user_view, z_buffer);
	if (screenshot == TRUE)
		take_screenshot(&img, game_info);
	mlx_put_image_to_window(mlx, window, img.ptr, 0, 0);
	mlx_destroy_image(mlx, img.ptr);
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
	if (!is_updated)
	{
		do_draw(mlx, window, game_info, user_view, screenshot);
		is_updated = TRUE;
	}
	return (0);
}

