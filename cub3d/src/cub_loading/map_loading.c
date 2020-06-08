/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 21:26:26 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/08 10:41:48 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./read_cub.h"

int		check_map(t_game_info *game_info)
{
	int		x;
	int		y;

	y = -1;
	while (++y < game_info->map_height - 1)
	{
		x = -1;
		while (++x < game_info->map_width)
		{
			if (game_info->map[y][x] == '0' || game_info->map[y][x] == 'N'
			|| game_info->map[y][x] == 'E' || game_info->map[y][x] == 'S'
			|| game_info->map[y][x] == 'W')
			{
				if (y == 0 || x == 0 || y + 1 == game_info->map_height
					|| x + 1 == game_info->map_width)
					return (ERROR);
				if (game_info->map[y - 1][x] == ' '
				|| game_info->map[y + 1][x] == ' '
				|| game_info->map[y][x - 1] == ' '
				|| game_info->map[y][x + 1] == ' ')
					return (ERROR);
			}
		}
	}
	return (0);
}

int		get_map(int fd, t_game_info *game_info)
{
	int			i;
	char		*line;
	int			j;
	int			k;

	k = 0;
	game_info->map = ft_calloc(game_info->map_height + 1, sizeof(char *));
	while ((i = get_next_line(fd, &line)))
	{
		if (i == ERROR)
			return (ERROR);
		i = 0;
		while (*(line + i) == ' ')
			i++;
		if (*(line + i) == '1')
		{
			j = game_info->map_width - ft_strlen(line);
			while (j--)
				line = supreme_cat(line, " ", game_info->map_width);
			*(game_info->map + k++) = ft_strdup(line);
		}
		free(line);
	}
	free(line);
	return (0);
}

int		get_map_widthy(int fd, t_game_info *game_info)
{
	int			i;
	char		*line;
	int			x;

	while ((i = get_next_line(fd, &line)))
	{
		game_info->map_height++;
		x = 0;
		if (i == ERROR)
			return (ERROR);
		while (*(line + x) == ' ')
			x++;
		while (*(line + x) == '1' || *(line + x) == '0'
			|| *(line + x) == '2' || *(line + x) == 'N'
			|| *(line + x) == 'S' || *(line + x) == 'E' || *(line + x) == 'W')
			x++;
		game_info->map_width = x < game_info->map_width
							? game_info->map_width
							: x;
		free(line);
	}
	free(line);
	return (0);
}
