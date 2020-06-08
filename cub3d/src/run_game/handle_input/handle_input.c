/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:09:04 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/08 14:42:28 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

extern int g_is_updated;

int		handle_input(int keycode, void **infos)
{
	t_user_view		*user_view;
	t_game_info		*game_info;

	user_view = (t_user_view *)infos[0];
	game_info = (t_game_info *)infos[1];
	if (keycode == KEY_W)
		move_forward(*game_info, user_view);
	else if (keycode == KEY_S)
		move_backward(*game_info, user_view);
	else if (keycode == KEY_A)
		move_leftward(*game_info, user_view);
	else if (keycode == KEY_D)
		move_rightward(*game_info, user_view);
	else if (keycode == KEY_RIGHT)
		turn_right(user_view);
	else if (keycode == KEY_LEFT)
		turn_left(user_view);
	else if (keycode == KEY_ESC)
		exit(0);
	g_is_updated = FALSE;
	return (0);
}
