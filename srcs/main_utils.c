/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:34:33 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/18 13:34:01 by yobougre         ###   ########.fr       */
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
	data->z_val = 1;
	return (help);
}

void	ft_scale(t_data *img)
{
	if (img->map.col_len <= 20 || img->map.line_len <= 20)
		img->scale = 1.5;
	else if (img->map.col_len <= 50 || img->map.line_len <= 50)
		img->scale = 0.8;
	else if (img->map.col_len <= 100 || img->map.line_len <= 100)
		img->scale = 0.35;
	else if (img->map.col_len <= 200 || img->map.line_len <= 200)
		img->scale = 0.12;
	else if (img->map.col_len >= 600 || img->map.line_len >= 600)
		img->scale = 0.1;
	img->scale /= (float)HEIGHT / (float)WIDTH * 2;
}

void	ft_drawer(mlx_data *data)
{
	ft_draw_y(data->img);
	ft_draw_x(data->img);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0 , 0);
	mlx_destroy_image(data->mlx, data->img->img);
}

void	ft_utils(mlx_data *data, t_data *img)
{
	ft_proj_point(data->img);
	ft_move_center(img, ft_init_center(img));
	ft_drawer(data);
}
