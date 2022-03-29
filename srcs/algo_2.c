/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:14:21 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/29 19:54:55 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

t_float   ft_projection(t_point pos)
{
	int		angle;
	int		rad_120;
	t_float	proj;

	rad_120 = 120 * (M_PI / 180.0);
	angle = 30 * (M_PI / 180.0);
	proj.x1 = pos.x1 * cos(angle) 
		+ pos.y1 * cos(angle + rad_120) + pos.z * cos(angle - rad_120);
	proj.y1 = pos.x1 * sin(angle) 
		+ pos.y1 * sin(angle + rad_120) + pos.z * sin(angle - rad_120);
	return (proj);
}
