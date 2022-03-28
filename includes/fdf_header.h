/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:25:02 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/28 12:14:32 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
# define FDF_HEADER_H
# include "struct.h"
# include "includes.h"
# include "../libft/libft.h" 
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
char	*ft_read_map(char *name, t_map_line *map);
void	ft_free_tab(char **tab);

#endif
