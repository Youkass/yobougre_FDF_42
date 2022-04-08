/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:05:32 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/08 18:34:59 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

/*
w : 119
a : 97
s : 115
d : 100
esc : 65307
+ : 61
- : 45

*/
void	ft_scale_up(mlx_data *data)
{
	int	i;
	int	j;
	int scale;

	i = 0;
	if (data->img->scale <= 0)
		return ;
	printf("scale : %f\n", data->img->scale);
	data->img->scale += 0.01;
	scale = data->img->scale * O_SCL;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord[i][j].x = data->img->coord[i][j].x + 
				(scale * j);
			data->img->coord[i][j].y = data->img->coord[i][j].y + 
				(scale * i);
			++j;
		}
		++i;
	}
	initialize_image(data->img, data);
	ft_drawer(data);
}


void	ft_scale_down(mlx_data *data)
{
	int	i;
	int	j;
	int scale;

	i = 0;
	if (data->img->scale - 0.01 <= 0)
		return ;
	printf("scale : %f\n", data->img->scale);
	data->img->scale -= 0.01;
	scale = data->img->scale * O_SCL;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord[i][j].x = data->img->coord[i][j].x - 
				(scale * j);
			data->img->coord[i][j].y = data->img->coord[i][j].y - 
				(scale * i);
			++j;
		}
		++i;
	}
	initialize_image(data->img, data);
	ft_drawer(data);
}

int	ft_move(int keycode, void *params)
{
	if (keycode == 119)
		ft_up(params);
	else if (keycode == 97)
		ft_left(params);
	else if (keycode == 115)
		ft_down(params);
	else if (keycode == 100)
		ft_right(params);
	else if (keycode == 61)
		ft_scale_up(params);
	else if (keycode == 45)
		ft_scale_down(params);
	else if (keycode == 120)
		ft_rotate_x_hooks(params);
	else if (keycode == 121)
		ft_rotate_y_hooks(params);
	else if (keycode == 122)
		ft_rotate_z_hooks(params);
	else if (keycode == 65307)
		ft_escape(params);
	return (0);
}

