/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:19:35 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/10 14:52:01 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

static int ft_diff_x(t_data *data, t_help help)
{
	int	diff;

	diff = data->coord[help.i][help.j].x - help.x;
	if (diff >= -1 && diff <= 1)
		return (1);
	else
		return (0);
}

static int ft_diff_y(t_data *data, t_help help)
{
	int	diff;

	diff = data->coord[help.i][help.j].y - help.y;
	if (diff >= -1 && diff <= 1)
		return (1);
	else
		return (0);
}

int	ft_check_pos(t_data *data)
{
	int	i;
	int	j;

	i = data->map.col_len - 1;
	j = data->map.line_len - 1;
	if (data->coord[i][j].y > HEIGHT)
		return (1);
	else if (data->coord[0][j].x > WIDTH - 1)
		return (1);
	else if (data->coord[i][0].x < 0)
		return (1);
	else if (data->coord[0][0].y < 0)
		return (1);
	return (0);
}

void	ft_move_center(t_data *data)
{
	t_help	help;

	help.x = WIDTH / 2;
	help.y = HEIGHT / 2;
	help.i = data->map.col_len / 2;
	help.j = data->map.line_len / 2;
	while (!ft_diff_x(data, help))
	{
		if (help.x > data->coord[help.i][help.j].x)
			ft_move_right(data);
		else
			ft_move_left(data);
	}
	while (!ft_diff_y(data, help))
	{
		if (help.y > data->coord[help.i][help.j].y)
			ft_move_down(data);
		else
			ft_move_up(data);
	}
}
