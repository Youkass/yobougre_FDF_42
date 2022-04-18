/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:44:00 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/18 13:44:19 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	ft_scale_only_z(t_data *img)
{
	int	res;

	res = (img->map.col_len * img->map.line_len) * 0.008;
	if (img->map.col_len > 100 || img->map.line_len > 100)
		res = 1;
	return (res);
}

t_point	ft_to_iso(t_point coord, int scale)
{
	t_point	output;

	(void)scale;
	output.x = (coord.x - coord.y) * cos(ft_degree_to_rad(60));
	output.y = (coord.x + coord.y) * cos(ft_degree_to_rad(60)) + (-coord.z);
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
