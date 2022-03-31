/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:22:06 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/31 18:23:06 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

static t_point	*ft_fill_t_point(t_data *data, int i)
{
	t_point	*output;
	int		k;
	int		j;

	output = malloc(sizeof(t_point) * (data->map.line_len));
	if (!output)
		return (NULL);
	k = 0;
	j = 0;
	while (k < data->map.line_len)
	{
		output[k].z = data->map.lines[i][j];
		output[k].x = j + 1;
		output[k].y = i + 1;
		++j;
		++k;
	}
	return (output);
}

t_point	**ft_parse_point(t_data *data)
{
	t_point	**output;
	int		i;
	int		k;

	output = malloc(sizeof(t_point *) * (data->map.col_len));
	if (!output)
		return (NULL);
	i = 0;
	k = 0;
	while (i < data->map.col_len)
	{
		output[k] = ft_fill_t_point(data, i);
		if (!output[k])
			return (NULL); //TODO
		++i;
		++k;
	}
	return (output);
}
