/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:39:20 by yobougre          #+#    #+#             */
/*   Udraw.pdated: 2022/03/28 14:20:55 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

t_point ft_to_iso(t_point coord, int scale)
{
	t_point	output;

	output.x = coord.x - coord.y;
	output.y = (coord.y + coord.x / 2) - coord.z * scale;
	output.z = coord.z;
	output.color = coord.color;
	return (output);
}

void	ft_draw_y(t_data *img)
{
	int		i;
	int		j;
	t_float	point;

	j = 0; 
	while (j < img->map.line_len)
	{
		i = 0;
		while (i < img->map.col_len - 1)
		{
			point.color_1 = img->coord[i][j].color;
			point.color_2 = img->coord[i + 1][j].color;
			point.x1 = img->coord[i][j].x;
			point.x2 = img->coord[i + 1][j].x;
			point.y1 = img->coord[i][j].y;
			point.y2 = img->coord[i + 1][j].y;
			ft_draw_line(point, img);
			++i;
		}
		++j;
	}
}

void	ft_draw_x(t_data *img)
{
	int		i;
	int		j;
	t_float	point;

	i = 0;
	while (i < img->map.col_len)
	{
		j = 0;
		while (j < img->map.line_len - 1)
		{
			point.color_1 = img->coord[i][j].color;
			point.color_2 = img->coord[i][j + 1].color;
			point.x1 = img->coord[i][j].x;
			point.x2 = img->coord[i][j + 1].x;
			point.y1 = img->coord[i][j].y;
			point.y2 = img->coord[i][j + 1].y;
			ft_draw_line(point, img);
			++j;
		}
		++i;
	}
}

void	ft_proj_point(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->map.col_len)
	{
		j = 0;
		while (j < img->map.line_len)
		{
			img->coord[i][j].x *= img->scale;
			img->coord[i][j].y *= img->scale;
			img->coord[i][j] = ft_to_iso(img->coord[i][j], img->scale);
			++j;
		}
		++i;
	}
}
