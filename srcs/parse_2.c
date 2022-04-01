/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:22:06 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/01 14:04:58 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

static t_point	*ft_fill_t_point(t_data *data, int i, int origin)
{
	t_point	*output;
	int		k;
	int		j;
	int		origin_y;

	output = malloc(sizeof(t_point) * (data->map.line_len));
	if (!output)
		return (NULL);
	k = 0;
	origin_y = 20;
	j = 0;
	while (k < data->map.line_len)
	{
		output[k].z = data->map.lines[i][j];
		output[k].x = origin_y + 1;
		output[k].y = origin + 1;
		++j;
		++origin_y;
		++k;
	}
	return (output);
}

t_point	**ft_parse_point(t_data *data)
{
	t_point	**output;
	int		i;
	int		origin;
	int		k;

	output = malloc(sizeof(t_point *) * (data->map.col_len));
	if (!output)
		return (NULL);
	i = 0;
	origin = -10;
	k = 0;
	while (i < data->map.col_len)
	{
		output[k] = ft_fill_t_point(data, i, origin);
		if (!output[k])
			return (NULL); //TODO
		++i;
		++origin;
		++k;
	}
	return (output);
}
