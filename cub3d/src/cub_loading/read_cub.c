/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:13:25 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/17 19:13:25 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"


#include <stdio.h>
int			open_cub_file(char *path)
{
	int		fd;
	size_t	len;

	if (!path)
		exit_with_errmsg("no path.");
	len = ft_strlen(path);

	if (path[len - 4] != '.' || path[len - 3] != 'c' ||
		path[len - 2] != 'u' || path[len - 1] != 'b' )
		exit_with_errmsg("please enter the right extension.");
	if ((fd = open(path, O_RDONLY)) == ERROR)
		exit_with_errmsg(strerror(errno));
	return (fd);
}

char	check_type(char *line, t_game_info *game_info)
{
	if (*line == 'N' && *(line + 1) == 'O')
		return (!game_info->north ? 'N' : ERROR);
	else if (*line == 'S' &&  *(line + 1) == 'O')
		return (!game_info->south ? 'S' : ERROR);
	else if (*line == 'W' && *(line + 1) == 'E')
		return (!game_info->west ? 'W' : ERROR);
	else if (*line == 'E' && *(line + 1) == 'A')
		return (!game_info->east ? 'E' : ERROR);
	else if (*line == 'R')
		return (!game_info->res ? 'R' : ERROR);
	else if (*line == 'F')
		return (!game_info->floor ? 'F' : ERROR);
	else if (*line == 'C')
		return (!game_info->ceilling ? 'C' : ERROR);
	else if (*line == 'S')
		return (!game_info->sprite ? 's' : ERROR);
	return (FALSE);
}

int		set_type_info_nswes(char type, char *line, t_game_info *game_info)
{
	while (*line == ' ')
		line++;
	if (type == 'N')
		if (!(game_info->north = ft_strdup(line)))
			return (ERROR);
	if (type == 'S')
		if (!(game_info->south = ft_strdup(line)))
			return (ERROR);
	if (type == 'W')
		if (!(game_info->west = ft_strdup(line)))
			return (ERROR);
	if (type == 'E')
		if (!(game_info->east = ft_strdup(line)))
			return (ERROR);
	if (type == 's')
		if (!(game_info->sprite = ft_strdup(line - 1)))
			return (ERROR);
	while (*line != ' ' && *line != 0)
		line++;
	while (*line == ' ')
		line++;
	if (*line != 0)
		return (ERROR);
	return (0);
}

int		set_type_info_floor(char *line, t_game_info *game_info)
{
	int	i;

	i = -1;
	while (*line == ' ')
		line++;
	if (!(game_info->floor = malloc(3 * sizeof(int))))
		return (ERROR);
	while (++i < 3)
		game_info->floor[i] = -1;
	i = -1;
	while (++i < 3)
	{
		game_info->floor[i] = ft_atoi(line);
		while ('0' <= *line && *line <= '9')
			line++;
		if (*line == ',' && i != 2)
			line++;
		while (*line == ' ')
			line++;
	}
	if (*line != 0 || game_info->floor[0] < 0 || game_info->floor[1] < 0 || game_info->floor[2] < 0)
		return (ERROR);
	return (0);
}

int		set_type_info_ceilling(char *line, t_game_info *game_info)
{
	int	i;

	i = -1;
	while (*line == ' ')
		line++;
	if (!(game_info->ceilling = malloc(3 * sizeof(int))))
		return (ERROR);
	while (++i < 3)
		game_info->ceilling[i] = -1;
	i = -1;
	while (++i < 3)
	{
		game_info->ceilling[i] = ft_atoi(line);
		while ('0' <= *line && *line <= '9')
			line++;
		if (*line == ',' && i != 2)
			line++;
		while (*line == ' ')
			line++;
	}
	if (*line != 0 || game_info->ceilling[0] < 0 || game_info->ceilling[1] < 0 || game_info->ceilling[2] < 0)
		return (ERROR);
	return (0);
}

int		set_type_info_res(char *line, t_game_info *game_info)
{
	game_info->res = malloc(sizeof(int) * 2);
	if (!game_info->res)
		return (ERROR);
	game_info->res[0] = ft_atoi(line);
	while (*line == ' ')
		line++;
	while ('0' <= *line && *line <= '9')
		line++;
	if (*line != ' ')
		return (ERROR);
	game_info->res[1] = ft_atoi(line);
	while (*line == ' ')
		line++;
	while ('0' <= *line && *line <= '9')
		line++;
	while (*line == ' ')
		line++;
	if (*line != 0 || game_info->res[0] < 0 || game_info->res[1] < 0)
		return (ERROR);
	return (0);
}

int		set_type_info(char type, char *line, t_game_info *game_info)
{
	t_bool errchk;

	if (type == 'N' || type == 'S' || type == 'W'
	 || type == 'E' || type == 's')
	{
		if ((errchk = set_type_info_nswes(type, line + 2, game_info)) == ERROR)
			return (ERROR);
	}
	else if (type == 'R')
	{
		if ((errchk = set_type_info_res(line + 1, game_info)) == ERROR)
			return (ERROR);
	}
	else if (type == 'F')
	{
		if ((errchk = set_type_info_floor(line + 1, game_info)) == ERROR)
			return (ERROR);
	}
	else if (type == 'C')
	{
		if ((errchk = set_type_info_ceilling(line + 1, game_info)) == ERROR)
			return (ERROR);
	}
	else
		return (ERROR);
	return (0);
}

int		get_type(int fd, t_game_info *game_info)
{
	int		i;
	char	*line;
	int		result;
	char	type;

	result = 0;
	while ((i = get_next_line(fd, &line))) // check options
	{
		if (i == ERROR)
			return (ERROR);
		while (*line == ' ')
			line++;
		if ((type = check_type(line, game_info)))
		{
			if (set_type_info(type, line, game_info) == ERROR)
				result = ERROR;
		}
		else if (type == ERROR)
			result = ERROR;
		else
			break ;
		free(line);
	}
	free(line);
	return (result);
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
		write(1, "h", 1);
		while (*(line + x) == ' ')
			x++;
		while (*(line + x) == '1' || *(line + x) == '0'
			|| *(line + x) == '2' ||	*(line + x) == 'N'
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

int		get_map(int fd, t_game_info *game_info)
{
	int			i;
	char		*line;
	int			space;
	int			j;
	int			k;

	k = 0;
	game_info->map = ft_calloc(game_info->map_height + 1, sizeof(char *));
	space = 0;
	while ((i = get_next_line(fd, &line)))
	{
		if (i == ERROR)
			return (ERROR);
		while (*(line + space) == ' ')
			space++;
		if (*(line + space) == '1')
		{
			j = game_info->map_width - ft_strlen(line);
			while (j--)
				line = supreme_cat(line ," ", game_info->map_width);
			*(game_info->map + k++) = ft_strdup(line);
		}
		free(line);
	}
	free(line);
	return (0);
}

int			check_map(t_game_info *game_info)
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
					|| x + 1 == game_info->map_width )
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

t_bool		still_has_line(int fd)
{
	char *line;

	if (get_next_line(fd, &line))
	{
		free(line);
		return (TRUE);
	}
	free(line);
	return (FALSE);
}

t_game_info	read_cub_file(char *path)
{
	t_game_info		game_info;
	int				type_err;
	int				map_err;
	int				map_widthy_err;
	int				fd;

	fd = open_cub_file(path);
	game_info = init_game_info();
	type_err = get_type(fd, &game_info);
	map_widthy_err = get_map_widthy(fd, &game_info);

	close(fd);
	fd = open(path, O_RDONLY);
	map_err =get_map(fd, &game_info);
	write(1, "k\n", 2);
	if (type_err == ERROR || map_widthy_err == ERROR || map_err == ERROR
	|| still_has_line(fd) || check_map(&game_info) == ERROR)
	{
		free_game_info(&game_info);
		exit_with_errmsg("invalid cub file");
	}
	return (game_info);
}
