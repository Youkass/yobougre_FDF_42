/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:23:14 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/01 14:04:57 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void	ft_print(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.map.col_len)
	{
		j = 0;
		while (j < data.map.line_len)
		{
			printf("x : %f   y : %f \n", data.coord[i][j].x, data.coord[i][j].y);
			++j;
		}
		++i;
	}
}

int	main(void)
{
	mlx_data	data;
	t_data		img;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Wassup world");
	img.img = mlx_new_image(data.mlx , HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	if (ft_fill_int_tab(&img.map, ft_split_line(ft_read_map("pyramide.fdf", &img.map))) < 0)
		return (-1);
	img.scale = 10;
	img.coord = ft_parse_point(&img);
	if (!img.coord)
		return (-1);
	ft_proj_point(&img);
	ft_print(img);
	ft_draw_y(&img);
	ft_draw_x(&img);
	mlx_put_image_to_window(data.mlx, data.mlx_win, img.img, 0 , 0);
	mlx_loop(data.mlx);
}
