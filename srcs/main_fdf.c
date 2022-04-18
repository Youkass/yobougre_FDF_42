/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:15:35 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/18 13:34:01 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	main(int ac, char **av)
{
	mlx_data	data;
	t_data		img;

	if (ac == 2)
	{
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Wassup world");
		initialize_image(&img, &data);
		if (open(av[1], 0) < 0)
			return (0);
		if (ft_fill_int_tab(&img.map, ft_split_line(ft_read_map(av[1], &img.map))) < 0)
			return (-1);
		data.img = &img;
		ft_scale(&img);
		img.coord = ft_parse_point(&img);
		img.coord_cart = ft_dup_coord(&img);
		img.origin = ft_dup_coord(&img);
		if (!img.coord)
			return (-1);
		ft_utils(&data, &img);
		mlx_hook(data.mlx_win, 02, (1L<<0), ft_shut, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
