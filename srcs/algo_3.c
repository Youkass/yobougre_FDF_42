/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:04:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/31 18:20:18 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

float	ft_abs(float nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

t_draw	ft_init_draw(t_float point)
{
	t_draw	drw;

	drw.dx = point.x2 - point.x1;
	drw.dy = point.y2 - point.y1;
	drw.dx1 = ft_abs(drw.dx);
	drw.dy1 = ft_abs(drw.dy);
	drw.px = 2 * drw.dy1 - drw.dx1;
	drw.py = 2 * drw.dx1 - drw.dy1;
	return (drw);
}
