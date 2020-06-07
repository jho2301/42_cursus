/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 20:57:02 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/07 21:45:32 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

void		load_texture(void *mlx, char *path, t_image *img)
{
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->w, &img->h);
	img->data = (int *)mlx_get_data_addr(img->ptr,
	&img->bpp, &img->sizeline, &img->endian);
}
