/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:14:21 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/30 13:59:37 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

t_point  ft_projection(float x, float y, float z)
{
	//int		angle;
	//int		rad_120;
	t_point	proj;

	//rad_120 = 120 /** (M_PI / 180.0)*/;
	//angle = 30 /** (M_PI / 180.0)*/;
	//printf("%f, %f\n", x, y);
	//proj.x = x * cos(angle) 
	//	+ y * cos(angle + rad_120) + z * cos(angle - rad_120);
	//proj.y = x * sin(angle) 
	//	+ y * sin(angle + rad_120) + z * sin(angle - rad_120);
	//proj.y = proj.y * -1;
	//printf("%f, %f\n", proj.x, proj.y);
	proj.x = (x - z) / sqrt(2); 
	proj.y = (x + 2 * y + z) / sqrt(6);
	return (proj);
}

void	ft_draw_2_point_x(t_float pos, t_data *img)
{
	t_draw	draw;	

	draw.dx = pos.x2 - pos.x1;
	draw.dy = pos.y2 - pos.y1;
	draw.x = pos.x1;
	draw.y = pos.y1;
	draw.p = 2 * draw.dy - draw.dx;
	while (draw.x < pos.x2)
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

void    ft_draw_2_point_y(t_float pos, t_data *img)
{
	t_draw	draw;	

	draw.dx = pos.x2 - pos.x1;
	draw.dy = pos.y2 - pos.y1;
	draw.x = pos.x1;
	draw.y = pos.y1;
	draw.p = 2 * draw.dx - draw.dy;
	while (draw.y < pos.y2)
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

t_float	ft_conv_to_iso(float x1, float y1, float x2, float y2)
{
	t_float	iso;

	iso.x1 = x1;
	iso.y1 = y1;
	iso.x2 = x2;
	iso.y2 = y2;
	return (iso);
}


void	ft_draw_y(t_data *data)
{
	int	i;
	int	j;
	int	scale;

	i = 1;
	scale = 40;
	while (i < data->map.col_len)
	{
		j = 1;
		while (j < data->map.line_len + 1)
		{
			printf("x: %d,y: %d\n", j*20, i*20);
			ft_draw_2_point_y(ft_conv_to_iso(j * scale, i * scale, j  * scale, (i + 1) * scale), data);
			j++;
		}
		i++;
	}
}


void	ft_draw(t_data *data)
{
	int	i;
	int	j;
	int scale;

	i = 1;
	scale = 40;
	while (i < data->map.col_len + 1)
	{
		j = 1;
		while (j < data->map.line_len)
		{
			//printf("x: %d,y: %d\n", j*20, i*20);
			
			ft_draw_2_point_x(ft_conv_to_iso(j * scale, i * scale, (j + 1) * scale, i * scale), data);
			j++;
		}
		i++;
	}
	ft_draw_y(data);
}
