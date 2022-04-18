# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 11:07:05 by yobougre          #+#    #+#              #
#    Updated: 2022/04/18 13:54:18 by yobougre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MAIN= 	srcs/main_fdf.c

SRCS=	srcs/mandat_hooks.c\
		srcs/proj_utils.c\
		srcs/main_utils.c\
		srcs/mlx_utils_1.c\
		srcs/ft_free.c\
		srcs/utils.c\
		srcs/algo_1.c\
		srcs/algo_2.c\
		srcs/algo_3.c\
		srcs/parse_2.c\
		srcs/convert_base.c\
		srcs/convert_utils.c\
		srcs/parse_1.c\
		srcs/hooks.c\
		srcs/hooks_move.c\
		srcs/rotate.c\
		srcs/move_center.c\
		srcs/utils_center.c\
		srcs/rotate_hooks.c

SRCS_BNS= srcs/fdf.c
		  


INC=	includes/struct.h\
		includes/includes.h\
		includes/fdf_header.h

CC=	gcc

CFLAGS=	-Wall -Wextra -Werror -g3
MLX= mlx_Linux

OBJS= $(SRCS:.c=.o)

MAIN_OBJS= $(MAIN:.c=.o)

BONUS_OBJS= $(SRCS_BNS:.c=.o)

BONUS_NAME= fdf_bonus

RM= rm -f

NAME= fdf

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


all: $(NAME)

$(NAME): $(MLX) $(OBJS) $(INC) $(MAIN_OBJS)
		 @$(MAKE) -C libft
		 @echo "fdf : libft compiled"
		 @$(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) $(MAIN_OBJS) $(INC) libft/libft.a -Lmlx -lmlx_Linux -lXext -lX11 -lm -lz
		 @echo "fdf : compiled"
bonus:	$(MLX) $(OBJS) $(INC) $(BONUS_OBJS)
		 @$(MAKE) -C libft
		 @echo "fdf : libft compiled"
		 @$(CC) -g $(CFLAGS) -o $(BONUS_NAME) $(OBJS) $(BONUS_OBJS) $(INC) libft/libft.a -Lmlx -lmlx_Linux -lXext -lX11 -lm -lz
		 @echo "fdf : compiled"

$(MLX):
		cd mlx && ./configure
		@echo "fdf : minilibx compiled" 
clean:
		@$(MAKE) -C libft clean
		@$(RM) $(OBJS) $(MAIN_OBJS) $(BONUS_OBJS)
		cd mlx && ./configure clean
		@echo "fdf : objects has been erased"

fclean:	clean
		@$(MAKE) -C libft fclean
		@$(RM) $(NAME) $(MAIN_OBJS) $(BONUS_OBJS)
		@echo "fdf : objects and name has been erased"

re: fclean all

.PHONY: bonus all clean fclean re
