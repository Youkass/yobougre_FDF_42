/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:34:15 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/08 11:02:46 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	ft_check_place(t_data *data)
{
	int	i;
	int	j;

	i = data->map.col_len - 1;
	j = data->map.line_len - 1;
	if (data->coord[i][j].x > WIDTH)
		return (1);
	else if (data->coord[0][j].x > WIDTH)
		return (2);
	else if (data->coord[i][0].y > HEIGHT)
		return (3);
	else if (data->coord[0][0].y < 0)
		return (4);
	return (0);
}
