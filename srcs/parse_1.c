/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:29:16 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/24 08:09:23 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

static int	ft_split_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

static int	ft_fill_int_tab(t_map_line *map, char *line)
{
	char	**tmp_split;
	int		i;

	tmp_split = ft_split(line, ' ');
	if (!tmp_split)
		return (-1);
	free(line);
	map->line = malloc(sizeof(int *) * map->line_len);
	if (!map->line)
		return (ft_free(tmp_split), -1);
}

static char	**ft_split_line(char *line)
{
	char	**output;

	output = ft_split(line, '\n');
	if (!output)
		return (free(line), NULL);
	return (output);
}

char	*ft_read_map(char *name, t_map_line *map)
{
	int		fd;
	char	*line;
	char	*output;
	int		i;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		output = ft_strjoin_pimp(output, line); 
		if (!output)
			return (NULL);
		free(line);
		++i;
	}
	map->line_len = i;
	close(fd);
	return (output);
}
