/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 16:28:28 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/08 10:45:55 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_loading/read_cub.h"
#include "run_game/run_game.h"
#include "util/libft.h"

int		main(int argc, char *argv[])
{
	t_game_info		game_info;
	t_bool			screenshot_mode;

	check_argc(argc);
	screenshot_mode = check_screenshot_option(argc, argv[2]);
	game_info = read_cub_file(argv[1]);
	run_game(&game_info, screenshot_mode);
	free_game_info(&game_info);
	return (0);
}
