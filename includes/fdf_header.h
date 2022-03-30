/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:25:02 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/30 13:38:38 by hrecolet         ###   ########.fr       */
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
void    ft_draw_line_x(t_float *pos, t_data *img);
void	ft_draw_x(t_data *img, float seg_size);
void	ft_init_x(t_float *pos, float seg_size);
void	ft_init_y(t_float *pos, float seg_size);
//void	ft_draw_y(t_data *img, float seg_size);
//void    ft_draw_line_y(t_float *pos, t_data *img);
t_point	*ft_parse_point(t_data *data);
t_point  ft_projection(float x, float y, float z);
t_point	*ft_3d_to_2d(t_data *data);
void	ft_draw_2_point(float x1, float y1, float x2, float y2, t_data *img);
void	ft_draw(t_data *data);

#endif
