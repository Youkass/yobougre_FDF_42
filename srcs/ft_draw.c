/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:49:14 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/18 13:50:35 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void	ft_writeline_x(t_draw *draw, t_data *img)
{
	while (draw->x < draw->xe)
	{
		draw->x++;
		if (draw->px < 0)
			draw->px = draw->px + 2 * draw->dy1;
		else
		{
			if ((draw->dx < 0 && draw->dy < 0)
				|| (draw->dx > 0 && draw->dy > 0))
				draw->y++;
			else
				draw->y--;
			draw->px = draw->px + 2 * (draw->dy1 - draw->dx1);
		}
		ft_mlx_pixel_put(img, draw->x, draw->y, 0x00FF0000);
	}
}

void	ft_writeline_y(t_draw *draw, t_data *img)
{
	while (draw->y < draw->ye)
	{
		draw->y++;
		if (draw->py <= 0)
			draw->py = draw->py + 2 * draw->dx1;
		else
		{
			if ((draw->dx < 0 && draw->dy < 0)
				|| (draw->dx > 0 && draw->dy > 0))
				draw->x++;
			else
				draw->x--;
			draw->py = draw->py + 2 * (draw->dx1 - draw->dy1);
		}
		ft_mlx_pixel_put(img, draw->x, draw->y, 0x00FF0000);
	}
}

void	ft_draw_v(t_float pts, t_draw *draw, t_data *img)
{
	if (draw->dy >= 0)
	{
		draw->x = pts.x1;
		draw->y = pts.y1;
		draw->xe = pts.y2;
	}
	else
	{
		draw->x = pts.x2;
		draw->y = pts.y2;
		draw->xe = pts.y1;
	}
	ft_mlx_pixel_put(img, draw->x, draw->y, 0x00FF0000);
	ft_writeline_y(draw, img);
}

void	ft_draw_h(t_float pts, t_draw *draw, t_data *img)
{
	if (draw->dx >= 0)
	{
		draw->x = pts.x1;
		draw->y = pts.y1;
		draw->xe = pts.x2;
	}
	else
	{
		draw->x = pts.x2;
		draw->y = pts.y2;
		draw->xe = pts.x1;
	}
	ft_mlx_pixel_put(img, draw->x, draw->y, 0x00FF0000);
	ft_writeline_x(draw, img);
}

void	ft_draw_2_point(t_float pts, t_data *data)
{
	t_draw	draw;

	draw.dx = pts.x2 - pts.x1;
	draw.dy = pts.y2 - pts.y1;
	draw.dx1 = ft_abs(draw.dx);
	draw.dy1 = ft_abs(draw.dy);
	draw.px = 2 * draw.dy1 - draw.dx1;
	draw.py = 2 * draw.dx1 - draw.dy1;
	if (draw.dy1 <= draw.dx1)
		ft_draw_h(pts, &draw, data);
	else
		ft_draw_v(pts, &draw, data);
}
