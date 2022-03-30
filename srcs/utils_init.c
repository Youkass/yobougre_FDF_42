/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:08:05 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/30 11:44:04 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void	ft_init_x(t_float *pos, float seg_size)
{
	pos->x1 = WIDTH * 0.1;
	pos->y1 = HEIGHT * 0.1;
	pos->x2 = pos->x1 + seg_size;
	pos->y2 = pos->y1;
//	ft_projection(&pos->x2, &pos->y2, 0);
}

void	ft_init_y(t_float *pos, float seg_size)
{
	pos->x1 = WIDTH * 0.1;
	pos->y1 = HEIGHT * 0.1;
	pos->x2 = pos->x1;
	pos->y2 = pos->y1 + seg_size;
//	ft_projection(&pos->x2, &pos->y2, 0);
}
