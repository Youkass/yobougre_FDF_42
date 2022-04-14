/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:06:36 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/14 14:49:24 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_help
{
	int	i;
	int	j;
	int	x;
	int	y;
}	t_help;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_int
{
	int	val;
	int	color;
	float x;
	float y;
}	t_int;

typedef struct s_map
{
	int		line_len;
	int		col_len;
	t_int	**lines;
}	t_map_line;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	float		scale;
	float		z_axis;
	float		y_axis;
	float		x_axis;
	int			z_val;
	t_point		**coord;
	t_point		**coord_cart;
	t_point		**origin;
	t_map_line	map;
}	t_data;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
}	mlx_data;

typedef struct s_float
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	int		color_1;
	int		color_2;
}	t_float;

typedef struct	s_draw
{
	float	dx;
	float	dy;
	float	dx1;
	float	dy1;
	float	px;
	float	py;
	float	xe;
	float	ye;
	float	x;
	float	y;
}	t_draw;

#endif
