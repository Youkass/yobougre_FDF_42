/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:23:14 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/15 17:05:41 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	main(void)
{
	void	*mlx;
	void	*img;
	void	*mlx_win;

	(void)mlx_win;
	(void)img;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 400, "Wassup world\n");
	img = mlx_new_image(mlx , 800, 400);
	mlx_loop(mlx);
}
