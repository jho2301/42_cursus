/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:13:22 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/17 19:13:22 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

t_game_info	init_game_info()
{
	t_game_info		game_info;

	game_info.res = 0;
	game_info.east = 0;
	game_info.west = 0;
	game_info.south = 0;
	game_info.north = 0;
	game_info.sprite = 0;
	game_info.ceilling = 0;
	game_info.floor = 0;
	game_info.map = 0;
	game_info.map_width = 0;
	game_info.map_height = 0;
	return (game_info);
}

void	free_game_info(t_game_info *game_info)
{
	int i;
	if (!game_info->ceilling)
		free(game_info->ceilling);
	if (!game_info->floor)
		free(game_info->floor);
	if (!game_info->north)
		free(game_info->north);
	if (!game_info->west)
		free(game_info->west);
	if (!game_info->south)
		free(game_info->south);
	if (!game_info->east)
		free(game_info->east);
	if (!game_info->res)
		free(game_info->res);
	i = -1;
	if (!game_info->map)
	{
		while (*(game_info->map + i))
			free(*(game_info->map + i));
		free(game_info->map);
	}
	if (!game_info->sprite)
		free(game_info->sprite);
}
