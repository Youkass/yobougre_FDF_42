/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:20:00 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/12 18:20:47 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

static void	ft_print_help(t_help help)
{
	printf("help.x : %d\n", help.x);
	printf("help.y : %d\n", help.y);
}

t_help	ft_save_center(t_data *data)
{
	t_help	help;
	
	help.j = data->map.line_len / 2;
	help.i = data->map.col_len / 2;
	help.x = data->coord[help.i][help.j].x;
	help.y = data->coord[help.i][help.j].y;
	return (help);
}

void	ft_rotate_x_hooks(mlx_data *data)
{
	int		i;
	int		j;
	t_help	save;

	i = 0;
	save = ft_save_center(data->img);
	data->img->x_axis += 0.05;	
	if (data->img->x_axis >= 6.05)
		data->img->x_axis = 1;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord_cart[i][j] = ft_rotate_x(data->img->coord_cart[i][j]
				, 5);
			j++;
		}
		i++;
	}
	ft_proj_point_2(data->img);
	ft_move_center(data->img, save);
	ft_move_right(data->img);
	ft_move_down(data->img);
	ft_print_help(save);
	ft_print_help(ft_save_center(data->img));
	if (!ft_diff_x(data->img, save) || !ft_diff_y(data->img, save))
		ft_move_center(data->img, save);
	initialize_image(data->img, data);
	ft_drawer(data);
}

void	ft_rotate_y_hooks(mlx_data *data)
{
	int	i;
	int	j;
	t_help	save;

	i = 0;
	save = ft_save_center(data->img);
	data->img->y_axis += 0.05;	
	if (data->img->y_axis >= 360)
		data->img->y_axis = 1;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord_cart[i][j] = ft_rotate_y(data->img->coord_cart[i][j]
				, 5);
			j++;
		}
		i++;
	}
	ft_proj_point_2(data->img);
	ft_move_center(data->img, save);
	ft_move_right(data->img);
	ft_move_down(data->img);
	ft_print_help(save);
	ft_print_help(ft_save_center(data->img));
	if (!ft_diff_x(data->img, save) || !ft_diff_y(data->img, save))
		ft_move_center(data->img, save);
	initialize_image(data->img, data);
	ft_drawer(data);
}

void	ft_rotate_z_hooks(mlx_data *data)
{
	int	i;
	int	j;
	t_help	save;

	i = 0;
	save = ft_save_center(data->img);
	data->img->z_axis += 0.05;	
	if (data->img->z_axis >= 6.05)
		data->img->z_axis = 1;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord_cart[i][j] = ft_rotate_z(data->img->coord_cart[i][j]
				, 5);
			j++;
		}
		i++;
	}
	ft_proj_point_2(data->img);
	ft_move_center(data->img, save);
	ft_move_right(data->img);
	ft_move_down(data->img);
	ft_print_help(save);
	ft_print_help(ft_save_center(data->img));
	if (!ft_diff_x(data->img, save) || !ft_diff_y(data->img, save))
		ft_move_center(data->img, save);
	initialize_image(data->img, data);
	ft_drawer(data);
}
