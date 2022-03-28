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

void	ft_init(t_float *pos, float seg_size)
{
	pos->x1 = WIDTH * 0.1;
	pos->y1 = HEIGHT * 0.2;
	pos->x2 = pos->x1 + seg_size;
	pos->y2 = pos->y1 + seg_size;
}

void	ft_draw_x(t_data *img)
{
	float	seg_size;
	int		line;
	t_float	pos;

	seg_size = 10;
	ft_init(&pos, seg_size);
	line = 0;
	while (line < img->map->line_len)
	{
		ft_draw_line(&pos, img);
		pos.x1 += seg_size;
		pos.y1 += seg_size;
		pos.x2 = pos.x1 + seg_size;
		pos.y2 = pos.y1 + seg_size;
		++line;
	}
}

void    ft_draw_line(t_float *pos, t_data *img)
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
