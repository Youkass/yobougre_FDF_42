/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:31:46 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/05 15:34:02 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void		initialize_image(t_data *fdf, mlx_data *mlx)
{
	t_data	*image;

	image = fdf;
	image->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &image->bpp,
			&image->line_len, &image->endian);
	image->bpp /= 8;
}


static int	index_matr(int row, int column, int map_width)
{
	return (row * map_width + column);
}

int	ft_mlx_pixel_put(t_data *data, float x, float y, int color)
{
	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return (0);
	*(int *)(data->addr + (int)(index_matr(y, x, WIDTH) * data->bpp)) = color;
	return (1);
}
