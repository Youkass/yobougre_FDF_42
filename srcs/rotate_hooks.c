/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:20:00 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/14 13:27:53 by yobougre         ###   ########.fr       */
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
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord_cart[i][j] = 
				ft_rotate_x(data->img->coord_cart[i][j], 2);
			data->img->origin[i][j] = 
				ft_rotate_x(data->img->origin[i][j], 2);
			j++;
		}
		i++;
	}
	ft_proj_point_2(data->img);
	ft_re_center(data, save);
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
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord_cart[i][j] = 
				ft_rotate_y(data->img->coord_cart[i][j], 2);
			data->img->origin[i][j] = 
				ft_rotate_y(data->img->origin[i][j], 2);
			j++;
		}
		i++;
	}
	ft_proj_point_2(data->img);
	ft_re_center(data, save);
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
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord_cart[i][j] = 
				ft_rotate_z(data->img->coord_cart[i][j], 2);
			data->img->origin[i][j] = 
				ft_rotate_z(data->img->origin[i][j], 2);
			j++;
		}
		i++;
	}
	ft_proj_point_2(data->img);
	ft_re_center(data, save);
	initialize_image(data->img, data);
	ft_drawer(data);
}
