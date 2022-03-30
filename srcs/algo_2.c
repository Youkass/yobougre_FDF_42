/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:14:21 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/30 14:28:31 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

t_point   ft_projection(int x, int y, int z)
{
	int		angle;
	int		rad_120;
	t_point	proj;

	rad_120 = 120 * (M_PI / 180.0);
	angle = 30 * (M_PI / 180.0);
	proj.x = x * cos(angle) 
		+ y * cos(angle + rad_120) + z * cos(angle - rad_120);
	proj.y = x * sin(angle) 
		+ y * sin(angle + rad_120) + z * sin(angle - rad_120);
	proj.z = z;
	return (proj);
}

