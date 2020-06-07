/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_info_loading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 21:30:19 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/07 21:45:03 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./read_cub.h"

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
		if (!(game_info->sprite = ft_strdup(line)))
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
	if (*line != 0 || game_info->floor[0] < 0
	|| game_info->floor[1] < 0 || game_info->floor[2] < 0)
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
	if (*line != 0 || game_info->ceilling[0] < 0
		|| game_info->ceilling[1] < 0 || game_info->ceilling[2] < 0)
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
