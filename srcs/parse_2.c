/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:22:06 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/04 16:55:19 by yobougre         ###   ########.fr       */
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
	int i;
	int	j;
	
	i = data->map.line_len / 2;
	j = data->map.col_len / 2;
	while (j > 0)
	{
		lines[i][j].x--;
		lines[i][j].y--;
		--j;
	}
	while (i-- > 0)
	{
		j = data->map.line_len - 1;
		while (j > 0)
		{
			lines[i][j].x--;
			lines[i][j].y--;
			--j;
		}
		--i;
	}
}

static void	ft_refill_lines(t_int **lines, t_data *data)
{
	int i;
	int	j;
	
	i = data->map.line_len / 2;
	j = data->map.col_len / 2;
	lines[i][j].x = WIDTH / 2;
	lines[i][j].y = HEIGHT / 2;
	while (j < data->map.line_len)
	{
		lines[i][j].x++;
		lines[i][j].y++;
		++j;
	}
	while (i++ < data->map.col_len)
	{
		j = 0;
		while (j < data->map.line_len)
		{
			lines[i][j].x++;
			lines[i][j].y++;
			++j;
		}
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
