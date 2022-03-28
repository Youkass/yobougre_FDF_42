/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:31:46 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/28 15:56:30 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void	ft_mlx_pixel_put(t_data *data, float x, float y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return ;
	dst = data->addr + (int)(y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
