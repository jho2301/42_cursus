#include "run_game.h"

int		run_game(t_game_info *game_info, t_bool screenshot)
{
    void			*mlx;
    void			*window;
	t_user_view 	user_view;

	mlx = mlx_init();
    window = mlx_new_window(mlx, game_info->res[RES_W_IDX], game_info->res[RES_H_IDX], "HWANO'S 3D");
	get_user_info(game_info, &user_view);
	mlx_key_hook(window, handle_input, (void *[]){&user_view, game_info});
	mlx_loop_hook(mlx, draw, (void *[]){&user_view, game_info, mlx, window, &screenshot});
	mlx_loop(mlx);
    return (0);
}

