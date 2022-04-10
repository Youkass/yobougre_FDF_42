/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:20:00 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/10 16:08:35 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void	ft_rotate_x_hooks(mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->img->x_axis += 0.05;	
	if (data->img->x_axis >= 6.05)
		data->img->x_axis = 0;
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
	initialize_image(data->img, data);
	ft_drawer(data);
}

void	ft_rotate_y_hooks(mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->img->y_axis += 0.5;
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
	initialize_image(data->img, data);
	ft_drawer(data);
}

void	ft_rotate_z_hooks(mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->img->z_axis += 0.05;	
	if (data->img->z_axis >= 360)
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
	initialize_image(data->img, data);
	ft_drawer(data);
}
