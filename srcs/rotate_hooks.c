/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:20:00 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/11 15:42:53 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

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
	printf("x_axis : %f\n", data->img->x_axis);
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord[i][j] = ft_rotate_x(data->img->coord[i][j]
				, data->img->x_axis);
			j++;
		}
		i++;
	}
	ft_move_center(data->img, save);
	ft_move_down(data->img);
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
		data->img->y_axis = 0;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord[i][j] = ft_rotate_y(data->img->coord[i][j]
				, data->img->y_axis);
			j++;
		}
		i++;
	}
	ft_move_center(data->img, save);
	ft_move_right(data->img);
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
		data->img->z_axis = 0;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord[i][j] = ft_rotate_z(data->img->coord[i][j]
				, data->img->z_axis);
			j++;
		}
		i++;
	}
	ft_move_center(data->img, save);
	ft_move_right(data->img);
	initialize_image(data->img, data);
	ft_drawer(data);
}
