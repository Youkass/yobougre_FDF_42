/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:22:06 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/30 16:50:37 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"


t_point	*ft_parse_point(t_data *data)
{
	t_point	*output;
	int		i;
	int		j;
	int		k;

	output = malloc(sizeof(t_point) * data->map.col_len * data->map.line_len);
	if (!output)
		return (NULL);
	i = 1;
	k = 0;
	while (i < data->map.col_len)
	{
		j = 1;
		while (j < data->map.line_len)
		{
			output[k].z = data->map.lines[i][j];
			output[k].x = j;
			output[k].y = i;
			++k;
			++j;
		}
		++i;
	}
	return (output);
}

void	ft_proj_point(t_data *img)
{
	int	i;
	int scale;

	i = 0;
	scale = 20;
	while (i < img->map.col_len * img->map.line_len)
	{
		img->coord[i].x *= scale;
		img->coord[i].y *= scale;
		img->coord[i] = ft_toIsometric2D(img->coord[i].x, img->coord[i].y, img->coord[i].z);
		++i;
	}
}

t_point ft_toIsometric2D(float x,float y,float z)
{
	t_point	output;

	output.x = x + y;
	output.y = y - x / 2;
	output.z = z;
	return (output);
}

void	ft_draw(mlx_data *data, t_data img)
{
	int	i;
	t_float	point;

	i = 0;
	while (i < img.map.col_len * img.map.line_len - 1)
	{
		point.x1 = img.coord[i].x;
		point.x2 = img.coord[i + 1].x;
		point.y1 = img.coord[i].y;
		point.y2 = img.coord[i + 1].y;
		draw_line(data, point);
		++i;
	}
}

