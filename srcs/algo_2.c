/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:14:21 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/29 16:44:21 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void    ft_projection(float *x, float *y, float z)
{
	int		angle;
	int		rad_120;

	rad_120 = 120 * (M_PI / 180.0);
	angle = 30 * (M_PI / 180.0);
	*x =*x * cos(angle) + *y * cos(angle + rad_120) + z * cos(angle - rad_120);
	*y = *x * sin(angle) + *y * sin(angle + rad_120) + z * sin(angle - rad_120);
}
