/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:51:15 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/18 16:32:04 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void	ft_up(t_mlx_data *data)

{
	int	i;
	int	j;

	i = 0;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord[i][j].y -= 5;
			++j;
		}
		++i;
	}
	initialize_image(data->img, data);
	ft_drawer(data);
}

void	ft_left(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord[i][j].x -= 5;
			++j;
		}
		++i;
	}
	initialize_image(data->img, data);
	ft_drawer(data);
}

void	ft_down(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord[i][j].y += 5;
			++j;
		}
		++i;
	}
	initialize_image(data->img, data);
	ft_drawer(data);
}

void	ft_right(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->img->map.col_len)
	{
		j = 0;
		while (j < data->img->map.line_len)
		{
			data->img->coord[i][j].x += 5;
			++j;
		}
		++i;
	}
	initialize_image(data->img, data);
	ft_drawer(data);
}

int	ft_escape(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	ft_free_int_tab((void *)data->img->map.lines, data->img->map.col_len);
	ft_free_int_tab((void *)data->img->coord, data->img->map.col_len);
	ft_free_int_tab((void *)data->img->coord_cart, data->img->map.col_len);
	ft_free_int_tab((void *)data->img->origin, data->img->map.col_len);
	free(data->mlx);
	exit(1);
	return (0);
}
