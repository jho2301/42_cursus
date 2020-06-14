/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:13:12 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/08 14:37:50 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_GAME_H
# define RUN_GAME_H

# include <math.h>
# include <stdio.h>
# include "./minilibx/mlx.h"
# include "../cub_loading/read_cub.h"
# include "../util/libft.h"

# define RES_H_IDX	1
# define RES_W_IDX	0

# define KEY_RIGHT	124
# define KEY_LEFT	123
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

typedef struct		s_sprite_position
{
	double			spr_x;
	double			spr_y;
	double			inv_det;
	double			trans_x;
	double			trans_y;
	int				spr_screen_x;
	int				spr_h;
	int				draw_start_y;
	int				draw_end_y;
	int				spr_w;
	int				draw_start_x;
	int				draw_end_x;
}					t_spr_pos;

typedef struct		s_texture
{
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	double			wall_x;
}					t_texture;

typedef struct		s_dda
{
	int				x;
	int				side;
	double			raydir_x;
	double			raydir_y;
	float			perpwalldist;
	float			line_h;
	float			draw_start;
	float			draw_end;
	double			cam_x;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	int				step_x;
	int				step_y;
	int				hit;
}					t_dda;

typedef struct		s_user_view
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_user_view;

typedef struct		s_image
{
	void			*ptr;
	int				*data;
	int				sizeline;
	int				w;
	int				h;
	int				bpp;
	int				endian;
}					t_image;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			dist;
}					t_sprite;

typedef struct		s_bfh
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_bfh;

typedef struct		s_bih {
	unsigned int	size_header;
	unsigned int	w;
	unsigned int	h;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bih;

int					run_game(t_game_info *game_info, t_bool screenshot);
void				take_screenshot(t_image *img, t_game_info *game_info);
int					handle_input(int keycode, void **infos);
int					draw(void **infos);
void				get_user_info(t_game_info *game_info,
						t_user_view *user_view);
void				draw_floor_ceiling(t_game_info *game_info,
								void *mlx_ptr, t_image *img);
void				draw_wall(void *mlx, t_user_view user_view,
							t_game_info *game_info, void *vals[]);
void				draw_sprites(void *ptrs[], t_game_info game_info,
							t_user_view user_view, double z_buffer[]);
t_dda				raycast(t_game_info *game_info, t_user_view user_view,
							double z_buffer[], int x);
void				move_rightward(t_game_info g, t_user_view *u);
void				move_leftward(t_game_info g, t_user_view *u);
void				move_backward(t_game_info g, t_user_view *u);
void				move_forward(t_game_info g, t_user_view *u);
void				turn_right(t_user_view *u);
void				turn_left(t_user_view *u);
void				sort_sprites (t_sprite *sprites[], int num_sprites);
int					get_num_sprites (t_game_info game_info);
void				get_sprites_location(t_game_info g, t_user_view u,
										t_sprite **spr);
t_spr_pos			get_camera_position(int i, t_sprite *sprites[],
									t_user_view u, t_game_info g);
void				load_texture(void *mlx, char *path, t_image *img);

#endif
