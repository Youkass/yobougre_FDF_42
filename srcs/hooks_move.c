/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by yobougre          #+#    #+#             */
/*   Updated: 2022/04/08 12:30:46 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void	ft_up(mlx_data *data)

{
	int	i;
	int	j;

	i = 0;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord_cart[i][j].y -= 5;
			data->img->coord_cart[i][j].x -= 5;
			++j;
		}
		++i;
	}
	ft_proj_point(data->img);
	initialize_image(data->img, data);
	ft_drawer(data);
}

void	ft_left(mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord_cart[i][j].x -= 5;
			data->img->coord_cart[i][j].y += 3;
			++j;
		}
		++i;
	}
	ft_proj_point(data->img);
	initialize_image(data->img, data);
	ft_drawer(data);
}

void	ft_down(mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord_cart[i][j].y += 5;
			data->img->coord_cart[i][j].x += 5;
			++j;
		}
		++i;
	}
	ft_proj_point(data->img);
	initialize_image(data->img, data);
	ft_drawer(data);
}

void	ft_right(mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord_cart[i][j].x += 5;
			data->img->coord_cart[i][j].y -= 3;
			++j;
		}
		++i;
	}
	ft_proj_point(data->img);
	initialize_image(data->img, data);
	ft_drawer(data);
}

void	ft_escape(mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	ft_free_int_tab((void *)data->img->map.lines, data->img->map.col_len);
	ft_free_int_tab((void *)data->img->coord, data->img->map.col_len);
	free(data->mlx);
	exit(1);
}
