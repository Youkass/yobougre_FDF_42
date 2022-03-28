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

void	ft_draw(t_map_line map)
{

}

void    ft_draw_line(t_float *pos, mlx_data *data, t_data *img)
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
    //mlx_put_image_to_window(data->mlx, data->mlx_win, img->img, 0 , 0);
}
