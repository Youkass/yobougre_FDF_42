/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:39:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/18 13:44:25 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void	ft_proj_point(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->map.col_len)
	{
		j = 0;
		while (j < img->map.line_len)
		{
			img->coord_cart[i][j].x = img->origin[i][j].x
				+ ((O_SCL * img->scale) * (j + 1));
			img->coord_cart[i][j].y = img->origin[i][j].y
				+ ((O_SCL * img->scale) * (i + 1));
			img->coord_cart[i][j].z *= ft_scale_only_z(img);
			img->coord[i][j] = ft_to_iso(img->coord_cart[i][j], img->scale);
			++j;
		}
		++i;
	}
}

void	ft_proj_scale_up(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->map.col_len)
	{
		j = 0;
		while (j < img->map.line_len)
		{
			img->coord_cart[i][j].x += ((O_SCL * 0.01) * (j + 1));
			img->coord_cart[i][j].y += ((O_SCL * 0.01) * (i + 1));
			++j;
		}
		++i;
	}
}

void	ft_proj_scale_down(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->map.col_len)
	{
		j = 0;
		while (j < img->map.line_len)
		{
			img->coord_cart[i][j].x -= ((O_SCL * 0.01) * (j + 1));
			img->coord_cart[i][j].y -= ((O_SCL * 0.01) * (i + 1));
			++j;
		}
		++i;
	}
}

void	ft_proj_point_2(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->map.col_len)
	{
		j = 0;
		while (j < img->map.line_len)
		{
			img->coord[i][j] = ft_to_iso(img->coord_cart[i][j], img->scale);
			++j;
		}
		++i;
	}
}
