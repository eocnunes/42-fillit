# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 14:14:26 by enunes            #+#    #+#              #
#    Updated: 2017/08/11 22:34:03 by enunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = 	fillit.c \
		check_grid.c \
		get_puzzle.c \
		setup_pieces.c \
		create_grid.c \
		solve.c \
		tools.c \

OBJS = $(SRCS:.c=.o)

LIBFT = libft/

LIBALL = make -C $(LIBFT) all

LIBC = make -C $(LIBFT) clean

LIBFC = make -C $(LIBFT) fclean

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes -I libft/
LDFLAGS = -L $(LIBFT) -lft

all: $(NAME)

%.o: %.c
		@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
		@$(LIBALL)
		@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)
		@echo "fillit made"

clean:
		@$(LIBC)
		@rm -rf $(OBJS)

fclean: clean
		@$(LIBFC)
		@rm -rf $(NAME)

re: fclean all
