/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:23:14 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/28 14:31:40 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	main(void)
{
	mlx_data	data;
	t_data		img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, HEIGHT, WIDTH, "Wassup world");
	img.img = mlx_new_image(mlx , HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	if (ft_fill_int_tab(img.map, ft_split_line(ft_read_map("42.fdf", img.map))) < 0)
		return (-1);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0 , 0);
	mlx_loop(mlx);
}
