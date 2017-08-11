# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 14:14:26 by enunes            #+#    #+#              #
#    Updated: 2017/08/10 23:39:57 by gaguirre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFT = libft/

LIBRE = make -C $(LIBFT) re

LIBC = make -C $(LIBFT) clean

LIBFC= make -C $(LIBFT) fclean

SRCS = 	fillit.c \
		check_grid.c \
		get_puzzle.c \
		setup_pieces.c \
		create_grid.c \
		solve.c \
		tools.c \
		$(LIBFT)libft.a \

CC = gcc

CFLAGS = -Wall -Wextra -Werror -o -I includes

all: $(NAME)

$(NAME):
		@$(LIBRE)
		@$(CC) $(CFLAGS) $(NAME) $(SRCS)
		@echo "fillit made"

clean:
		@$(LIBC)

fclean: clean
		@$(LIBFC)
		@/bin/rm -f $(NAME)

re: fclean all
