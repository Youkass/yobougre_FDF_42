/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:15:35 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/18 16:38:56 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

static int	ft_open_maps(t_data *img)
{
	img->coord = ft_parse_point(img);
	if (!img->coord)
		return (-1);
	img->coord_cart = ft_dup_coord(img);
	if (!img->coord_cart)
		return (-1);
	img->origin = ft_dup_coord(img);
	if (!img->coord)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx_data	data;
	t_data		img;

	if (ac == 2)
	{
		if (open(av[1], 0) < 0)
			return (0);
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF MAGGLE");
		initialize_image(&img, &data);
		if (ft_fill_int_tab(&img.map,
				ft_split_line(ft_read_map(av[1], &img.map))) < 0)
			return (ft_escape(&data), -1);
		data.img = &img;
		ft_scale(&img);
		if (ft_open_maps(&img) < 0)
			return (ft_escape(&data), -1);
		ft_utils(&data, &img);
		mlx_hook(data.mlx_win, 17, 0L, ft_escape, &data);
		mlx_hook(data.mlx_win, 02, (1L << 0), ft_shut, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
