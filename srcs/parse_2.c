/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:06:53 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/13 09:41:23 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf_header.h"

static t_point	*ft_fill_t_point(t_data *data, int i)
{
	t_point	*output;
	int		k;
	int		j;

	output = malloc(sizeof(t_point) * (data->map.line_len + 1));
	if (!output)
		return (NULL);
	k = 0;
	j = 0;
	while (k < data->map.line_len)
	{
		output[k].z = data->map.lines[i][j].val;
		output[k].color = data->map.lines[i][j].color;
		output[k].x = data->map.lines[i][j].x;
		output[k].y = data->map.lines[i][j].y;
		++j;
		++k;
	}
	return (output);
}

static void	ft_refill_lines(t_int **lines, t_data *data)
{
	t_help	help;
	float	y;
	float	x;
	
	help.i = 0;
	y = HEIGHT / 2 - (data->map.col_len * (O_SCL * data->scale)) / 2;
	x = WIDTH / 2 - (data->map.line_len * (O_SCL * data->scale)) / 2;
	help.y = (y - x / 2) - HEIGHT / 12;
	while (help.i < data->map.col_len)
	{
		help.j = 0;
		help.x = x + y - WIDTH / 4;
		while (help.j <= data->map.line_len)
		{
			lines[help.i][help.j].x = help.x;
			lines[help.i][help.j].y = help.y; 
			help.x++;
			help.j++;
		}
		lines[help.i][help.j - 1].y = help.y;
		lines[help.i][help.j - 1].x = help.x;
		help.y++;
		help.i++;
	}
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
	ft_refill_lines(data->map.lines, data);
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
