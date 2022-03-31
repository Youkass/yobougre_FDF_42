/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:23:14 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/31 11:15:53 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	main(void)
{
	mlx_data	data;
	t_data		img;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Wassup world");
	img.img = mlx_new_image(data.mlx , HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	if (ft_fill_int_tab(&img.map, ft_split_line(ft_read_map("42.fdf", &img.map))) < 0)
		return (-1);
	//img.coord = ft_parse_point(&img);
	//if (!img.coord)
		//return (-1);
	ft_draw(&img);
	//ft_draw_x(&img, 25);
	//ft_draw_y(&img, 25);
	mlx_put_image_to_window(data.mlx, data.mlx_win, img.img, 0 , 0);
	mlx_loop(data.mlx);
}
