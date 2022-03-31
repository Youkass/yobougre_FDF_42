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

t_point ft_to_iso(float x,float y,float z)
{
	t_point	output;

	output.x = x + y;
	output.y = (y - x / 2) - z;
	output.z = z;
	return (output);
}

void	ft_draw_y(t_data *img)
{
	int		i;
	int		j;
	t_float	point;

	j = 0; 
	while (j < img->map.line_len - 1)
	{
		i = 0;
		while (i < img->map.col_len - 1)
		{
			point.x1 = img->coord[i][j].x;
			point.x2 = img->coord[i][j + 1].x;
			point.y1 = img->coord[i][j].y;
			point.y2 = img->coord[i][j + 1].y;
			point.z1 = img->coord[i][j].z;
			point.z2 = img->coord[i][j + 1].z;
	printf("x1 : %f y1 : %f\n", point.x1, point.y1);
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
	while (i < img->map.col_len - 1)
	{
		j = 0;
		while (j < img->map.line_len - 1)
		{
			point.x1 = img->coord[i][j].x;
			point.x2 = img->coord[i][j + 1].x;
			point.y1 = img->coord[i][j].y;
			point.y2 = img->coord[i][j + 1].y;
			point.z1 = img->coord[i][j].z;
			point.z2 = img->coord[i][j + 1].z;
	printf("x1 : %f y1 : %f\n", point.x1, point.y1);
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
					img->coord[i][j].y, img->coord[i][j].z);
			++j;
		}
		++i;
	}
}
