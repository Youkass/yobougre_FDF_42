/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:23:14 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/28 12:14:32 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"



int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	int		i;
	int		y;

	(void)mlx_win;
	(void)img;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, HEIGHT, WIDTH, "Wassup world");
	img.img = mlx_new_image(mlx , HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	y = 0;
	i = WIDTH / 2;
	while (y < 50)
	{
		i = 0;
		while (i < 50)
		{
			ft_mlx_pixel_put(&img, y, i, 0x00FF0000);
			mlx_put_image_to_window(mlx, mlx_win, img.img, 0 , 0);
			++i;
		}
		ft_mlx_pixel_put(&img, y, i, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0 , 0);
		y++;
	}
	mlx_loop(mlx);
}
