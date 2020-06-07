/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_info_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 21:23:09 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/07 22:39:01 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"


int		get_type(int fd, t_game_info *game_info)
{
	int		i;
	char	*line;
	int		result;
	int		j;

	result = 0;
	while ((i = get_next_line(fd, &line)))
	{
		if (i == ERROR)
			return (ERROR);
		j = 0;
		while (*(line + j) == ' ')
			j++;
		if ((result = check_type(line + j, game_info)))
		{
			if (set_type_info(result, line + j, game_info) == ERROR)
				result = ERROR;
		}
		else
			break ;
		free(line);
	}
	free(line);
	return (result);
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
