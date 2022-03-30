/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:22:06 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/30 12:43:19 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

t_point	*ft_parse_point(t_data *data)
{
	t_point	*output;
	int		i;
	int		j;
	int		k;
	int		scaling;
	
	scaling = 50;
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
			output[k].x = j * scaling;
			output[k].y = i * scaling;
			//printf("%f, %f\n", output[k].x, output[k].y);
			++k;
			++j;
		}
		++i;
	}
	return (output);
}
