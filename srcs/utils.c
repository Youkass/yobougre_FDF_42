/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:23:09 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/28 13:36:40 by yobougre         ###   ########.fr       */
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

int	*ft_fill_lines(char **values)
{
	int	*output;
	int	i;

	output = malloc(sizeof(int) * ft_tab_size(values));
	if (!output)
		return (NULL);
	i = 0;
	while (i < ft_tab_size(values))
	{
		output[i] = ft_atoi(values[i]);
		++i;
	}
	ft_free_tab(values);
	return (output);
}
