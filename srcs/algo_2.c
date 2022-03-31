/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:14:21 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/31 11:28:23y hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

t_float	ft_conv_to_iso(t_float pos)
{
	t_float	iso;

	iso.x1 = pos.x1 + pos.y1;
	iso.y1 = pos.y1 - pos.x1 / 2.0;
	iso.x2 = pos.x2 + pos.y2;
	iso.y2 = pos.y2 - pos.x2 / 2.0;
	return (iso);
}

void	ft_draw_y(t_data *data)
{
	int	i;
	int	j;
	int	scale;
	t_float pos;

	i = 1;
	scale = 20;
	while (i < data->map.col_len)
	{
		j = 1;
		while (j < data->map.line_len + 1)
		{
			//printf("x: %d,y: %d\n", j*20, i*20);
			pos.x1 = j * scale;
			pos.y1 = i * scale;
			pos.x2 = j * scale;
			pos.y2 = (i + 1) * scale;
			ft_draw_2_point(ft_conv_to_iso(pos), data);
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
	t_float pos;

	i = 1;
	scale = 20;
	while (i < data->map.col_len + 1)
	{
		j = 1;
		while (j < data->map.line_len)
		{
			//printf("x: %d,y: %d\n", j*20, i*20);
			pos.x1 = j * scale;
			pos.y1 = i * scale;
			pos.x2 = (j + 1) * scale;
			pos.y2 = i * scale;
			ft_draw_2_point(ft_conv_to_iso(pos), data);
			j++;
		}
		i++;
	}
	ft_draw_y(data);
}
