# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 14:14:26 by enunes            #+#    #+#              #
#    Updated: 2017/07/29 14:09:13 by gaguirre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = 	fillit.c \
		fillit_caller.c \
		check_grid.c \
		get_puzzle.c \
		trim_pieces.c \
		create_grid.c \
		solve.c \
		tools.c \

OBJS = $(SRCS:.c=.o)

LIBFT = libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes -I libft/
LDFLAGS = -L $(LIBFT) -lft

all: $(NAME)

%.o: %.c
		@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)
		@echo "fillit made"

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all
