/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:22:06 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/05 13:10:28 by yobougre         ###   ########.fr       */
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
		output[k].z = data->map.lines[i][j].val;
		output[k].color = data->map.lines[i][j].color;
		output[k].x = data->map.lines[i][j].x;
		output[k].y = data->map.lines[i][j].y;
		++j;
	++k;
	}
	return (output);
}

static void	ft_refill_lines_2(t_int **lines, t_data *data)
{
	t_help	help;
	
	help.j = data->map.line_len / 2;
	help.i = data->map.col_len / 2;
	help.x = WIDTH / 2;
	help.y = HEIGHT / 2;
	while (help.j > 0)
	{
		lines[help.i][help.j].x = help.x--;
		lines[help.i][help.j].y = help.y--;
		help.j--;
	}
	while (help.i >= 0)
	{
		help.j = data->map.line_len - 1;
		while (help.j >= 0)
		{
			lines[help.i][help.j].x = help.x--;
			lines[help.i][help.j].y = help.y--;
			help.j--;
		}
		help.i--;
	}
}

static void	ft_refill_lines(t_int **lines, t_data *data)
{
	t_help	help;
	
	help.j = data->map.line_len / 2;
	help.i = data->map.col_len / 2;
	help.x = WIDTH / 2;
	help.y = HEIGHT / 2;
	while (help.j < data->map.line_len)
	{
		lines[help.i][help.j].x = help.x++;
		lines[help.i][help.j].y = help.y++;
		help.j++;
	}
	help.i++;
	while (help.i < data->map.col_len)
	{
		help.j = 0;
		while (help.j < data->map.line_len)
		{
			lines[help.i][help.j].x = help.x++;
			lines[help.i][help.j].y = help.y++;
			help.j++;
		}
		help.i++;
	}
	ft_refill_lines_2(lines, data);
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
