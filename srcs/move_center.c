/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:19:35 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/08 17:38:42 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

void	ft_rescale(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->scale -= 0.01;
	while (i < data->map.col_len)
	{
		j = 0;
		while (j < data->map.line_len)
		{
			data->coord[i][j].x += (O_SCL * data->scale);
			data->coord[i][j].y += (O_SCL * data->scale);
			++j;
		}
		++i;
	}
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
		return (2);
	else if (data->coord[i][0].x < 0)
		return (3);
	else if (data->coord[0][0].y < 0)
		return (4);
	return (0);
}

static void	ft_updown(t_data *data)
{
	if (ft_check_pos(data) ==  3)
	{
		while (ft_check_pos(data) == 3)
			ft_move_right(data);
		if (ft_check_pos(data) == 2)
			ft_rescale(data);
	}
	else if (ft_check_pos(data) == 4)
	{
		while (ft_check_pos(data) == 4)
			ft_move_down(data);
		if (ft_check_pos(data) ==  1)
			ft_rescale(data);
	}
}

void	ft_move_center(t_data *data)
{
	printf("je suis la coucou \n");
	if (ft_check_pos(data) == 1)
	{
		while (ft_check_pos(data) == 1)
			ft_move_up(data);
		if (ft_check_pos(data) == 4)
			ft_rescale(data);
	}
	else if (ft_check_pos(data) == 2)
	{
		while (ft_check_pos(data) == 2)
			ft_move_left(data);
		if (ft_check_pos(data) == 3)
			ft_rescale(data);
	}
	else if (ft_check_pos(data) == 3 || ft_check_pos(data) == 4)
		ft_updown(data);
	if (data->scale <= 0.1)
		return ; 
	if (ft_check_pos(data))
		ft_move_center(data);
}
