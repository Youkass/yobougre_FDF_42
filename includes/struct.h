/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:15:07 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/29 14:12:20 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
}	mlx_data;

typedef struct s_map
{
	int	line_len;
	int	col_len;
	int	**lines;
}	t_map_line;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_map_line	map;
}	t_data;

typedef struct s_float
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
}	t_float;

typedef struct	s_draw
{
	float	dx;
	float	dy;
	float	p;
	float	x;
	float	y;
}	t_draw;
#endif
