/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:23:14 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/30 15:34:48 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	main(void)
{
	mlx_data	data;
	t_data		img;
	int			i = 0;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Wassup world");
	img.img = mlx_new_image(data.mlx , HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	if (ft_fill_int_tab(&img.map, ft_split_line(ft_read_map("Krai.fdf", &img.map))) < 0)
		return (-1);
	img.coord = ft_parse_point(&img);
	if (!img.coord)
		return (-1);
	ft_proj_point(&img);
	printf("%d\n", img.map.line_len * img.map.col_len);
	while (i < img.map.line_len * img.map.col_len)
	{
		printf("x : %f y : %f z : %f\n", img.coord[i].x, img.coord[i].y, img.coord[i].z);
		printf("i : %d\n", i);
		i++;
	}
	ft_draw_x(&img, 25);
	ft_draw_y(&img, 25);
	mlx_put_image_to_window(data.mlx, data.mlx_win, img.img, 0 , 0);
	mlx_loop(data.mlx);
}
