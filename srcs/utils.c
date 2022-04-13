/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:23:09 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/13 09:41:16 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	ft_tab_size(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (i);
	while (tab[i])
		++i;
	return (i);
}

static int	hextoint(const char *str)
{
	int		res;
	char	c;
	char	v;

	res = 0;
	while (*str)
	{
		c = *str++;
		v = ((c & 0xF) + (c >> 6)) | (((c >> 3) & 0x8));
		res = (res << 4) | (int) v;
	}
	return (res);
}

t_int	*ft_fill_lines(char **values)
{
	t_int	*output;
	char	**tmp;
	int		i;

	output = malloc(sizeof(t_int) * (ft_tab_size(values) + 200));
	if (!output)
		return (NULL);
	i = 0;
	while (i < ft_tab_size(values))
	{
		tmp = ft_split(values[i], ',');
		if (!tmp)
			return (ft_free_tab(values), free(output), NULL);
		output[i].val = ft_atoi(tmp[0]);
		if (ft_tab_size(tmp) == 2)
			output[i].color = hextoint(tmp[1]);
		else
			output[i].color = DEF_COLOR;
		ft_free_tab(tmp);
		++i;
	}
	ft_free_tab(values);
	return (output);
}

<<<<<<< HEAD
t_point	**ft_dup_coord(t_data *data)
{
	t_point	**res;
	int		i;
	int		j;
	
	i = 0;
	res = malloc(sizeof(t_point *) * data->map.col_len);
	while (i < data->map.col_len)
	{
		j = 0;
		res[i] = malloc(sizeof(t_point) * data->map.line_len);
		while (j < data->map.line_len)
		{
			res[i][j].x = data->coord[i][j].x;
			res[i][j].y = data->coord[i][j].y;
			res[i][j].z = data->coord[i][j].z;
			res[i][j].color = data->coord[i][j].color;
			j++;
		}
		i++;
	}
	return (res);
=======
float	ft_abs(float nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (nb * (-1));
>>>>>>> 0da09d608dfea73c59b18216d488c9b91c955ecc
}
