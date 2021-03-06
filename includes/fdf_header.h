/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/13 10:00:22 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
# define FDF_HEADER_H

# include "struct.h"
# include "includes.h"

/* -------------------------------------------------------------------------- */
/*                            FILE = srcs/rotate.c                            */
/* -------------------------------------------------------------------------- */
float	ft_degree_to_rad(int degree);
t_point	ft_rotate_x(t_point coord, int degree);
t_point	ft_rotate_z(t_point coord, int degree);
t_point	ft_rotate_y(t_point coord, int degree);
void	ft_re_center(mlx_data *data, t_help save);

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
int    ft_scale_only_z(t_data *img);
t_point	ft_to_iso(t_point coord, int scale);
void	ft_draw_y(t_data *img);
void	ft_draw_x(t_data *img);
void	ft_proj_point(t_data *img);
void	ft_proj_point_2(t_data *img);

/* -------------------------------------------------------------------------- */
/*                         FILE = srcs/rotate_hooks.c                         */
/* -------------------------------------------------------------------------- */
t_help	ft_save_center(t_data *data);
void	ft_rotate_x_hooks(mlx_data *data);
void	ft_rotate_y_hooks(mlx_data *data);
void	ft_rotate_z_hooks(mlx_data *data);

/* -------------------------------------------------------------------------- */
/*                         FILE = srcs/move_center.c                          */
/* -------------------------------------------------------------------------- */
int ft_diff_x(t_data *data, t_help help);
int ft_diff_y(t_data *data, t_help help);
int	ft_check_pos(t_data *data);
void	ft_move_center(t_data *data, t_help center);

/* -------------------------------------------------------------------------- */
/*                         FILE = srcs/utils_center.c                         */
/* -------------------------------------------------------------------------- */
void	ft_move_down(t_data *data);
void	ft_move_up(t_data *data);
void	ft_move_right(t_data *data);
void	ft_move_left(t_data *data);

/* -------------------------------------------------------------------------- */
/*                             FILE = srcs/fdf.c                              */
/* -------------------------------------------------------------------------- */
t_help	ft_init_center(t_data *data);
void	ft_print(t_data data);
void	ft_scale(t_data *img);
void	ft_drawer(mlx_data *data);
int	main(int ac, char **av);

/* -------------------------------------------------------------------------- */
/*                            FILE = srcs/utils.c                             */
/* -------------------------------------------------------------------------- */
int	ft_tab_size(char **tab);
t_int	*ft_fill_lines(char **values);
t_point	**ft_dup_coord(t_data *data);

/* -------------------------------------------------------------------------- */
/*                        FILE = srcs/convert_utils.c                         */
/* -------------------------------------------------------------------------- */
int	ft_check(char *base);
int	check_nbr(char c, char *base);
int	find_in_base(char c, char *base);

/* -------------------------------------------------------------------------- */
/*                          FILE = srcs/hooks_move.c                          */
/* -------------------------------------------------------------------------- */
void	ft_up(mlx_data *data);
void	ft_left(mlx_data *data);
void	ft_down(mlx_data *data);
void	ft_right(mlx_data *data);
void	ft_escape(mlx_data *data);

/* -------------------------------------------------------------------------- */
/*                            FILE = srcs/hooks.c                             */
/* -------------------------------------------------------------------------- */
void	ft_scale_up(mlx_data *data);
void	ft_scale_down(mlx_data *data);
int	ft_move(int keycode, void *params);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/ft_free.c                            */
/* -------------------------------------------------------------------------- */
void	ft_free_tab(char **tab);
void	ft_free_int_tab(void **tab, int size);

/* -------------------------------------------------------------------------- */
/*                            FILE = srcs/algo_4.c                            */
/* -------------------------------------------------------------------------- */
int	ft_check_place(t_data *data);

/* -------------------------------------------------------------------------- */
/*                         FILE = srcs/mlx_utils_1.c                          */
/* -------------------------------------------------------------------------- */
void		initialize_image(t_data *fdf, mlx_data *mlx);
void	ft_mlx_pixel_put(t_data *data, float x, float y, int color);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/parse_1.c                            */
/* -------------------------------------------------------------------------- */
int	ft_fill_int_tab(t_map_line *map, char **lines);
char	**ft_split_line(char *line);
char	*ft_read_map(char *name, t_map_line *map);


#endif
