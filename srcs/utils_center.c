/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_center.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:28:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/12 17:09:23 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void	ft_move_down(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.col_len)
	{
		j = 0;
		while (j < data->map.line_len)
		{
			data->coord[i][j].y += 1;
			++j;
		}
		++i;
	}
}

void	ft_move_up(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.col_len)
	{
		j = 0;
		while (j < data->map.line_len)
		{
			data->coord[i][j].y -= 1;
			++j;
		}
		++i;
	}
}

void	ft_move_right(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.col_len)
	{
		j = 0;
		while (j < data->map.line_len)
		{
			data->coord[i][j].x += 1;
			++j;
		}
		++i;
	}
}

void	ft_move_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.col_len)
	{
		j = 0;
		while (j < data->map.line_len)
		{
			data->coord[i][j].x -= 1;
			++j;
		}
		++i;
	}
}
