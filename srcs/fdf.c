/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:06:43 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/11 12:00:05 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf_header.h"

t_help	ft_init_center(t_data *data)
{
	t_help	help;

	help.x = WIDTH / 2;
	help.y = HEIGHT / 2;
	help.i = data->map.col_len / 2;
	help.j = data->map.line_len / 2;
	return (help);
}

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

void	ft_scale(t_data *img)
{
	int	res;

	if (WIDTH / img->map.line_len < HEIGHT / img->map.col_len)
		res = HEIGHT / img->map.col_len;
	else
		res = WIDTH / img->map.line_len;
	res *= 0.20;
	img->scale = res;
	img->scale = 1;
}

void	ft_drawer(mlx_data *data)
{
	ft_draw_y(data->img);
	ft_draw_x(data->img);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0 , 0);
	mlx_destroy_image(data->mlx, data->img->img);
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
		data.img = &img;
		img.x_axis = 0;
		img.y_axis = 0;
		img.z_axis = 0;
		ft_scale(&img);
		img.coord = ft_parse_point(&img);
		img.coord_cart = ft_dup_coord(&img);
		if (!img.coord)
			return (-1);
		ft_proj_point(data.img);
		ft_move_center(&img, ft_init_center(&img));
		ft_print(img);
		ft_drawer(&data);
		mlx_hook(data.mlx_win, 02, (1L<<0), ft_move, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
