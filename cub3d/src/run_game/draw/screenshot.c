/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:07:26 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/08 14:00:00 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../run_game.h"

t_bfh init_bfh(t_game_info *game_info)
{
	t_bfh bfh;
	int image_size;
	int file_size;

	image_size = game_info->res[RES_W_IDX] * game_info->res[RES_H_IDX];
	file_size = 54 + 4 * image_size;
	ft_memcpy(&bfh.bitmap_type, "BM", 2);
	bfh.file_size       = file_size;
	bfh.reserved1       = 0;
	bfh.reserved2       = 0;
	bfh.offset_bits     = 0;
	return(bfh);
}

t_bih init_bih(t_game_info *game_info)
{
	t_bih bih;
	int image_size;
	int file_size;

	image_size = game_info->res[RES_W_IDX] * game_info->res[RES_H_IDX];
	file_size = 54 + 4 * image_size;
	bih.size_header = sizeof(bih);
	bih.w = game_info->res[RES_W_IDX];
	bih.h = -game_info->res[RES_H_IDX];
	bih.planes = 1;
	bih.bit_count = 24;
	bih.compression = 0;
	bih.image_size = file_size;
	bih.ppm_x = 72 * 40;
	bih.ppm_y = 72 * 40;
	bih.clr_used = 0;
	bih.clr_important = 0;
	return (bih);
}

void	take_screenshot(t_image *img, t_game_info *game_info)
{
	t_bfh			bfh;
	t_bih			bih;
	int				i;
	int				image_fd;
	unsigned char	color[3];

	image_fd = open("./screenshot.bpm", O_RDWR | O_CREAT);
	bfh = init_bfh(game_info);
	bih = init_bih(game_info);
	write(image_fd, &bfh, 14);
	write(image_fd, &bih, sizeof(bih));
	i = -1;
	while (++i < game_info->res[RES_W_IDX] * game_info->res[RES_H_IDX])
	{
		color[0]  = *(img->data + i) / (256 * 256);
		color[1] = *(img->data + i) / 256;
		color[2]  = *(img->data + i);
		write(image_fd, color, sizeof(color));
	}
	close(image_fd);
	exit(0);
}
