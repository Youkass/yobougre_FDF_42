/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by yobougre          #+#    #+#             */
/*   Updated: 2021/10/19 15:08:54 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
# define FDF_HEADER_H

# include "struct.h"
# include "includes.h"

/* -------------------------------------------------------------------------- */
/*                         FILE = srcs/convert_base.c                         */
/* -------------------------------------------------------------------------- */
int	ft_atoi_base(char *str, char *base);
void	output_size(int nb, int *size, char *base);
char	*ft_itoa_base(int nb, char *base, int m_size, char *output);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

/* -------------------------------------------------------------------------- */
/*                            FILE = srcs/algo_3.c                            */
/* -------------------------------------------------------------------------- */
float	ft_abs(float nb);
t_draw	ft_init_draw(t_float point);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/parse_2.c                            */
/* -------------------------------------------------------------------------- */
t_point	**ft_parse_point(t_data *data);

/* -------------------------------------------------------------------------- */
/*                            FILE = srcs/algo_2.c                            */
/* -------------------------------------------------------------------------- */
void	ft_draw_line(t_float point, t_data *img);

/* -------------------------------------------------------------------------- */
/*                            FILE = srcs/algo_1.c                            */
/* -------------------------------------------------------------------------- */
t_point	ft_to_iso(t_point coord, int scale);
void	ft_draw_y(t_data *img);
void	ft_draw_x(t_data *img);
void	ft_proj_point(t_data *img);

/* -------------------------------------------------------------------------- */
/*                             FILE = srcs/fdf.c                              */
/* -------------------------------------------------------------------------- */
void	ft_print(t_data data);
int	main(int ac, char **av);

/* -------------------------------------------------------------------------- */
/*                            FILE = srcs/utils.c                             */
/* -------------------------------------------------------------------------- */
int	ft_tab_size(char **tab);
t_int	*ft_fill_lines(char **values);

/* -------------------------------------------------------------------------- */
/*                        FILE = srcs/convert_utils.c                         */
/* -------------------------------------------------------------------------- */
int	ft_check(char *base);
int	check_nbr(char c, char *base);
int	find_in_base(char c, char *base);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/ft_free.c                            */
/* -------------------------------------------------------------------------- */
void	ft_free_tab(char **tab);
void	ft_free_int_tab(int **tab, int size);

/* -------------------------------------------------------------------------- */
/*                         FILE = srcs/mlx_utils_1.c                          */
/* -------------------------------------------------------------------------- */
int	ft_mlx_pixel_put(t_data *data, float x, float y, int color);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/parse_1.c                            */
/* -------------------------------------------------------------------------- */
int	ft_fill_int_tab(t_map_line *map, char **lines);
char	**ft_split_line(char *line);
char	*ft_read_map(char *name, t_map_line *map);


#endif
