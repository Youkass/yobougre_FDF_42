/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:14:21 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/01 14:41:45 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

static int	ft_first_p(t_float point, t_draw *drw, t_data *img)
{
	if (drw->dx >= 0)
	{
		drw->x = point.x1;
		drw->y = point.y1;
		drw->xe = point.x2;
	}
	else
	{
		drw->x = point.x2;
		drw->y = point.y2;
		drw->xe = point.x1;
	}
	if (!ft_mlx_pixel_put(img, drw->x, drw->y, DEF_COLOR))
		return (0);
	return (1);
}

static int	ft_scnd_p(t_float point, t_draw *drw, t_data *img)
{
	if (drw->dy >= 0)
	{
		drw->x = point.x1;
		drw->y = point.y1;
		drw->ye = point.y2;
	}
	else
	{
		drw->x = point.x2;
		drw->y = point.y2;
		drw->ye = point.y1;
	}
	if (!ft_mlx_pixel_put(img, drw->x, drw->y, DEF_COLOR))
		return (0);
	return (1);
}

static void	ft_line_x(t_float point, t_draw *drw, t_data *img)
{
	if (!ft_first_p(point, drw, img))
		return ;
	while (drw->x < drw->xe)
	{
		drw->x++;
		if (drw->px < 0)
			drw->px = drw->px + 2 * drw->dy1;
		else
		{
			if ((drw->dx < 0 && drw->dy < 0) || (drw->dx > 0 && drw->dy > 0))
				drw->y++;
			else
				drw->y--;
			drw->px = drw->px + 2 * (drw->dy1 - drw->dx1);
		}
		ft_mlx_pixel_put(img, drw->x, drw->y, DEF_COLOR);
	}
}

static void	ft_line_y(t_float point, t_draw *drw, t_data *img)
{
	if (!ft_scnd_p(point, drw, img))
		return ;
	while (drw->y < drw->ye)
	{
		drw->y++;
		if (drw->py <= 0)
			drw->py = drw->py + 2 * drw->dx1;
		else
		{
			if ((drw->dx < 0 && drw->dy < 0) || (drw->dx > 0 && drw->dy > 0))
				drw->x++;
			else
				drw->x--;
			drw->py = drw->py + 2 * (drw->dx1 - drw->dy1);
		}
		ft_mlx_pixel_put(img, drw->x, drw->y, DEF_COLOR);
	}
}

void	ft_draw_line(t_float point, t_data *img)
{
	t_draw	drw;

	drw = ft_init_draw(point);
	if (drw.dy1 <= drw.dx1)
		ft_line_x(point, &drw, img);
	else
		ft_line_y(point, &drw, img);
}
