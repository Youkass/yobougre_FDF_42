/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:15:07 by yobougre          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/28 12:09:22 by yobougre         ###   ########.fr       */
=======
/*   Updated: 2022/03/27 10:49:02 by yobougre         ###   ########.fr       */
>>>>>>> f1f08c70c447d80fb20ca0787ecfce2346b922cd
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_map
{
	int	line_len;
	int	col_len;
	int	**line;
}	t_map_line;

#endif
