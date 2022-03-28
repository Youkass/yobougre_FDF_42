# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yobougre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 16:14:22 by yobougre          #+#    #+#              #
#    Updated: 2022/03/28 12:12:34 by yobougre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=	srcs/fdf.c\
		srcs/mlx_utils_1.c
#		srcs/ft_free.c\
		srcs/parse_1.c


INC=	includes/struct.h\
		includes/includes.h

CC=	gcc

CFLAGS=	-Wall -Wextra -Werror -g3

MLX= mlx_Linux

OBJS= $(SRCS:.c=.o)

RM= rm -f

NAME= fdf

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


all: $(NAME)



$(NAME): $(MLX) $(OBJS) $(INC) 
		 @$(MAKE) -C libft
		 @echo "fdf : libft compiled"
		 @$(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) $(INC) libft/libft.a -Lmlx -lmlx_Linux -lXext -lX11 -lm -lz
		 @echo "fdf : compiled"

$(MLX):
		cd mlx && ./configure
		@echo "fdf : minilibx compiled" 
clean:
		@$(MAKE) -C libft clean
		@$(RM) $(OBJS)
		cd mlx && ./configure clean
		@echo "fdf : objects has been erased"

fclean:	clean
		@$(MAKE) -C libft fclean
		@$(RM) $(NAME)
		@echo "fdf : objects and name has been erased"

re: fclean all

.PHONY: bonus all clean fclean re
