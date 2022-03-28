/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:25:02 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/28 14:17:01 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
# define FDF_HEADER_H
# include "struct.h"
# include "includes.h"
# include "../libft/libft.h" 
/*=============================================================================*/
/*				FILE : ft_free.c											   */

void	ft_mlx_pixel_put(t_data *data, float x, float y, int color);
char	*ft_read_map(char *name, t_map_line *map);
int		ft_fill_int_tab(t_map_line *map, char **lines);
char	**ft_split_line(char *line);
/*=============================================================================*/
/*				FILE : ft_free.c											   */

void	ft_free_tab(char **tab);
void	ft_free_int_tab(int **tab, int size);

int	*ft_fill_lines(char **values);
int	ft_tab_size(char **tab);
int	*ft_fill_lines(char **values);
#endif
