/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:32:35 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/12 18:20:49 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

float	ft_degree_to_rad(int degree)
{
	return (degree * (M_PI / 180.0));
}

t_point	ft_rotate_x(t_point coord, int degree)
{
	t_point res;
	float	rad;

	rad = ft_degree_to_rad(degree);
	res.y = coord.y * cos(rad) + coord.z * sin(rad);
	res.z = coord.z * cos(rad) - coord.y * sin(rad);
	res.x = coord.x;
	res.color = coord.color;
	return (res);
}

t_point	ft_rotate_z(t_point coord, int degree)
{
	t_point	res;
	float	rad;

	rad = ft_degree_to_rad(degree);
	res.x = coord.x * cos(rad) - coord.y * sin(rad);
	res.y = coord.y * cos(rad) + coord.x * sin(rad);
	res.z = coord.z;
	res.color = coord.color;
	return (res);
}

t_point	ft_rotate_y(t_point coord, int degree)
{
	t_point	res;
	float	rad;

	rad = ft_degree_to_rad(degree);
	res.x = coord.x * cos(rad) + coord.z * sin(rad);
	res.z = coord.z * cos(rad) - coord.x * sin(rad);
	res.y = coord.y;
	res.color = coord.color;
	return (res);
}
