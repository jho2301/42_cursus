/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:13:17 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/17 19:13:17 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_CUB_H
# define READ_CUB_H

# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include "../util/libft.h"

# define TRUE	1
# define FALSE	0
# define ERROR	-1

typedef	int		t_bool;

/*
** res : int[2] width, height
*/

typedef struct	s_game_info
{
	int		*floor;
	int		*res;
	int		*ceilling;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int		map_width;
	int		map_height;
	char	**map;
}				t_game_info;

t_game_info		init_game_info();
void			free_game_info(t_game_info *game_info);
void			check_argc(int argc);
void			check_cub_file(char *path);
int				open_cub_file(char *path);
t_game_info		read_cub_file(char *path);
void			exit_with_errmsg(char *errmsg);
char			*supreme_cat(char *dst, char *src, int size);
char			check_type(char *line, t_game_info *game_info);
int				set_type_info(char type, char *line, t_game_info *game_info);
int				set_type_info_res(char *line, t_game_info *game_info);
int				set_type_info_ceilling(char *line, t_game_info *game_info);
int				set_type_info_floor(char *line, t_game_info *game_info);
int				set_type_info_nswes(char type, char *line, t_game_info *game_info);
int				get_type(int fd, t_game_info *game_info);
char			check_type(char *line, t_game_info *game_info);
int				get_map_widthy(int fd, t_game_info *game_info);
int				get_map(int fd, t_game_info *game_info);
int				check_map(t_game_info *game_info);



#endif
