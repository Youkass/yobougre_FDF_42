# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yobougre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 16:14:22 by yobougre          #+#    #+#              #
#    Updated: 2022/03/11 18:53:36 by yobougre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=	srcs/main_fdf.c


INC=	includes/struct.h\
		includes/includes.h

CC=		-Wall -Wextra -Werror -g3

.c.o:
		$(CC) -Imlx
