/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:23:09 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/02 01:51:43 by yobougre         ###   ########.fr       */
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
			output[i].color = ft_atoi(ft_convert_base(tmp[1], B_HX, B_10));
		else
			output[i].color = DEF_COLOR;
		ft_free_tab(tmp);
		++i;
	}
	ft_free_tab(values);
	return (output);
}
