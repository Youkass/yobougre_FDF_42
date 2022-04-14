/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:05:32 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/14 14:49:23 by yobougre         ###   ########.fr       */
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
	t_help	save;

	save = ft_save_center(data->img);
	data->img->scale += data->img->scale * 0.1;
	ft_proj_scale_up(data->img);
	ft_proj_point_2(data->img);
	ft_re_center(data, save);
	initialize_image(data->img, data);
	ft_drawer(data);
}


void	ft_scale_down(mlx_data *data)
{
	t_help	save;

	save = ft_save_center(data->img);
	data->img->scale -= data->img->scale * 0.1;
	ft_proj_scale_down(data->img);
	ft_proj_point_2(data->img);
	ft_re_center(data, save);
	initialize_image(data->img, data);
	ft_drawer(data);
}

static void	ft_move_z(mlx_data *data, int keycode)
{
	int		i;
	int		j;
	t_help	save;

	i = 0;
	save = ft_save_center(data->img);
	if (keycode == 65362)
		data->img->z_val += 0.1;
	else if(keycode == 65364)
		data->img->z_val -= 0.1;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			if (data->img->map.lines[i][j].val != 0)
				data->img->coord_cart[i][j].z *= data->img->z_val;
			++j;
		}
		++i;
	}
	ft_re_center(data, save);	
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
	else if (keycode == 65362 || keycode == 65364)
		ft_move_z(params, keycode);
	return (0);
}

