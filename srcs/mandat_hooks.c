/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandat_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:23:05 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/18 12:24:45 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	ft_shut(int keycode, void *params)
{
	if (keycode == 65307)
		ft_escape(params);
	return (0);
}
