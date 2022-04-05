/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:23:14 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/05 15:54:10 by hrecolet         ###   ########.fr       */
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

static void	ft_scale(t_data *img)
{
	int	res;

	if (WIDTH / img->map.line_len < HEIGHT / img->map.col_len)
		res = HEIGHT / img->map.col_len;
	else
		res = WIDTH / img->map.line_len;
	res *= 0.20;
	if (res % 2 == 1)
		res++;
	if (res == 0)
		res = 2;
	img->scale = res;
	printf("scale : %d\n", res);
}

int	main(int ac, char **av)
{
	mlx_data	data;
	t_data		img;

	if (ac == 2)
	{
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Wassup world");
		initialize_image(&img, &data);
		if (open(av[1], 0) < 0)
			return (0);
		if (ft_fill_int_tab(&img.map, ft_split_line(ft_read_map(av[1], &img.map))) < 0)
			return (-1);
		ft_scale(&img);
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
	return (0);
}
