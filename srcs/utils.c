/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:23:09 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/04 11:14:43 by hrecolet         ###   ########.fr       */
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

	output = malloc(sizeof(t_int) * ft_tab_size(values));
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
