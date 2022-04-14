/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_center.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:28:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/14 13:21:17 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void	ft_move_down(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.col_len)
	{
		j = 0;
		while (j < data->map.line_len)
		{
			data->coord[i][j].y += 1;
			++j;
		}
		++i;
	}
}

void	ft_move_up(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.col_len)
	{
		j = 0;
		while (j < data->map.line_len)
		{
			data->coord[i][j].y -= 1;
			++j;
		}
		++i;
	}
}

void	ft_move_right(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.col_len)
	{
		j = 0;
		while (j < data->map.line_len)
		{
			data->coord[i][j].x += 1;
			++j;
		}
		++i;
	}
}

void	ft_move_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.col_len)
	{
		j = 0;
		while (j < data->map.line_len)
		{
			data->coord[i][j].x -= 1;
			++j;
		}
		++i;
	}
}

void	ft_re_center(mlx_data *data, t_help save)
{
	ft_move_center(data->img, save);
	ft_move_right(data->img);
	ft_move_down(data->img);
	if (!ft_diff_x(data->img, save) || !ft_diff_y(data->img, save))
		ft_move_center(data->img, save);
}
