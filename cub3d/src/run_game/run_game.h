/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:13:12 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/17 19:13:12 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_GAME_H
# define RUN_GAME_H

# include <math.h>
# include <stdio.h>
# include "./minilibx/mlx.h"
# include "../cub_loading/read_cub.h"
# include "../util/libft.h"

# define SCREEN_HEIGHT	1
# define SCREEN_WIDTH	0

# define KEY_RIGHT		65363
# define KEY_LEFT		65361
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

typedef struct s_sprite_position
{
	double spriteX;
	double spriteY;
	double invDet;
	double transformX;
	double transformY;
	int spriteScreenX;
	int spriteHeight;
	int drawStartY;
	int drawEndY;
	int spriteWidth;
	int drawStartX;
	int drawEndX;
}				t_sprite_position;


typedef struct s_texture
{
	int texX;
	int texY;
	double step;
	double texPos;
	double		wallX;
}				t_texture;

typedef struct s_dda
{
	int		x;
	int		side;
	double	rayDirX;
	double	rayDirY;
	float	perpWallDist;
	float	lineHeight;
	float	drawStart;
	float	drawEnd;
	double	cameraX;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	int		stepX;
	int		stepY;
	int		hit;
}				t_dda;

typedef struct	s_user_view
{
	double	pos_x;
	double	pos_y;
    double	dir_x;
	double	dir_y;
    double	plane_x;
	double	plane_y;
}				t_user_view;

typedef struct s_image
{
	void		*ptr;
	int			*data;
	int			sizeline;
	int			width;
	int			height;
	int			bpp;
	int			endian;
}				t_image;

typedef struct s_sprite
{
	double	x;
	double	y;
	double	distance;
}			t_sprite;

int		run_game(t_game_info *game_info, t_bool screenshot);
void	take_screenshot(t_image *img, t_game_info *game_info);
int		handle_input(int keycode, void **infos);
int		draw(void **infos);
void	get_user_info(t_game_info *game_info, t_user_view *user_view);
void	draw_floor_ceiling(t_game_info *game_info, void *mlx_ptr, t_image *img);
void	draw_wall(void *mlx, t_user_view user_view, t_game_info *game_info, t_image img, t_dda dda);
void	draw_sprites(void *mlx, t_game_info game_info, t_user_view user_view, double ZBuffer[]);
t_dda	raycast(t_game_info *game_info, t_user_view user_view, double ZBuffer[], int x);
void	move_rightward(t_game_info g, t_user_view *u);
void	move_leftward(t_game_info g, t_user_view *u);
void	move_backward(t_game_info g, t_user_view *u);
void	move_forward(t_game_info g, t_user_view *u);
void	turn_right(t_user_view *u);
void	turn_left(t_user_view *u);

#endif
