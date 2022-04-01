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

t_point ft_to_iso(float x,float y,float z, int scale)
{
	t_point	output;

	output.x = x - y;
	output.y = (y + x / 2) - z * scale;
	output.z = z;
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
			img->coord[i][j] = ft_to_iso(img->coord[i][j].x, 
					img->coord[i][j].y, img->coord[i][j].z, img->scale);
			++j;
		}
		++i;
	}
}
