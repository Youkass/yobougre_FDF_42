# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yobougre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 16:14:22 by yobougre          #+#    #+#              #
#    Updated: 2022/03/14 16:57:55 by yobougre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=	srcs/fdf.c


INC=	includes/struct.h\
		includes/includes.h

CC=			gcc

CFLAGS=		-Wall -Wextra -Werror -g3

MLX= 	minilibx

OBJS= $(SRCS:.c=.o)

RM= rm -f

NAME= fdf


all: $(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(MLX):
		cd minilibx && ./configure
		@echo "fdf : minilibx compiled" 

$(NAME): $(MLX) $(OBJ) $(INC)
		 @$(MAKE) -C libft
		 @echo "fdf : libft compiled"
		 @$(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) $(INC) libft/libft.a -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
		 @echo "fdf : compiled"

clean:
		@$(MAKE) -C libft clean
		@$(RM) $(OBJS)
		cd minilibx && ./configure clean
		@echo "fdf : objects has been erased"

fclean:	clean
		@$(MAKE) -C libft fclean
		@$(RM) $(NAME)
		@echo "fdf : objects and name has been erased"

.PHONY: bonus all clean fclean 
