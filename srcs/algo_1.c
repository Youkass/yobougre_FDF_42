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

void	ft_draw_x(t_data *img)
{
	int		line;
	int		i;
	t_float	pos;

	line = 0;
	while (line < img->map.col_len)
	{
		i = 0;
		while (i < img->map.line_len - 1)
		{
			pos.x1 = img->coord[i].x;
			pos.x2 = img->coord[i + 1].x;
			pos.y1 = img->coord[i].y;
			pos.y2 = img->coord[i + 1].y;
			ft_draw_line_x(&pos, img);
			i++;
		}
		++line;
	}
}

void	ft_draw_y(t_data *img)
{

	int		line;
	int		i;
	t_float	pos;

	line = 0;
	while (line < img->map.col_len)
	{
		i = 0;
		while (i < img->map.line_len - 1)
		{
			pos.x1 = img->coord[i].x;
			pos.x2 = img->coord[i + 1].x;
			pos.y1 = img->coord[i].y;
			pos.y2 = img->coord[i + 1].y;
			ft_draw_line_x(&pos, img);
			i++;
		}
		++line;
	}
}


void    ft_draw_line_y(t_float *pos, t_data *img)
{
	t_draw	draw;	

	draw.dx = pos->x2 - pos->x1;
	draw.dy = pos->y2 - pos->y1;
	draw.x = pos->x1;
	draw.y = pos->y1;
	draw.p = 2 * draw.dx - draw.dy;
	while (draw.y < pos->y2)
	{
		if (draw.p >= 0)
		{
			ft_mlx_pixel_put(img, draw.x, draw.y, 0x00FF0000);
			draw.x = draw.x + 1;
			draw.p = draw.p + 2 * draw.dx - 2 * draw.dy;
		}
		else
		{
			ft_mlx_pixel_put(img, draw.x, draw.y, 0x00FF0000);
			draw.p = draw.p + 2 * draw.dx;
		}
		draw.y++;
	}
}

void    ft_draw_line_x(t_float *pos, t_data *img)
{
	t_draw	draw;	

	draw.dx = pos->x2 - pos->x1;
	draw.dy = pos->y2 - pos->y1;
	draw.x = pos->x1;
	draw.y = pos->y1;
	draw.p = 2 * draw.dy - draw.dx;
	while (draw.x < pos->x2)
	{
		if (draw.p >= 0)
		{
			ft_mlx_pixel_put(img, draw.x, draw.y, 0x00FF0000);
			draw.y = draw.y + 1;
			draw.p = draw.p + 2 * draw.dy - 2 * draw.dx;
		}
		else
		{
			ft_mlx_pixel_put(img, draw.x, draw.y, 0x00FF0000);
			draw.p = draw.p + 2 * draw.dy;
		}
		draw.x++;
	}
}

int	draw_line(mlx_data *data, t_float pos)
{
	float	delta_x;
	float	delta_y;
	float	pixel_x;
	float	pixel_y;
	int		pixels;

	delta_x = pos.x2 - pos.x1;
	delta_y = pos.y2 - pos.y1;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = pos.x1;
	pixel_y = pos.y1;
	while (pixels)
	{
		mlx_pixel_put(data->mlx, data->mlx_win, pixel_x, pixel_y, 0x00FF0000);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
	return (0);
}
