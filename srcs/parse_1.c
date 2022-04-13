/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:29:16 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/06 17:41:34 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	ft_fill_int_tab(t_map_line *map, char **lines)
{
	char	**tmp_split;
	int		i;

	map->lines = malloc(sizeof(t_int *) * map->col_len);
	if (!map->lines)
		return (ft_free_tab(lines), -1);
	i = 0;
	while (i < map->col_len)
	{
		tmp_split = ft_split(lines[i], ' ');
		if (!tmp_split)
			return (ft_free_tab(lines), -1);
		map->line_len = ft_tab_size(tmp_split);
		map->lines[i] = ft_fill_lines(tmp_split);
		if (!map->lines[i])
			return (ft_free_tab(lines), -1);
		++i;
	}
	ft_free_tab(lines);
	return (1);
}

char	**ft_split_line(char *line)
{
	char	**output;

	output = ft_split(line, '\n');
	if (!output)
		return (free(line), NULL);
	return (free(line),output);
}

char	*ft_read_map(char *name, t_map_line *map)
{
	int		fd;
	char	*line;
	char	*output;
	int		i;

	i = 1;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	output = NULL;
	while (i)
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
	map->col_len = i - 1;
	close(fd);
	return (output);
}
