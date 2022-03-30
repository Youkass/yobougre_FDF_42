/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:22:06 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/30 12:11:32 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"


t_point	*ft_parse_point(t_data *data)
{
	t_point	*output;
	int		i;
	int		j;
	int		k;

	output = malloc(sizeof(t_point) * data->map.col_len * data->map.line_len);
	if (!output)
		return (NULL);
	i = 0;
	k = 0;
	while (i < data->map.col_len)
	{
		j = 0;
		while (j < data->map.line_len)
		{
			output[k].z = data->map.lines[i][j];
			output[k].x = j;
			output[k].y = i;
			++k;
			++j;
		}
		++i;
	}
	return (output);
}
