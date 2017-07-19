# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 14:14:26 by enunes            #+#    #+#              #
#    Updated: 2017/07/17 21:33:23 by enunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = 	fillit.c \
		fillit_caller.c \
		read_tetriminos.c \
		check_grid.c \
		get_puzzle.c \
		trim_pieces.c \
		create_grid.c \
		solve.c \
		solve_caller.c \

OBJS = $(SRCS:.c=.o)

INCLUDE = includes/

LIBFT = libft/

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
		@$(CC) -c $(FLAGS) $< -o $@

$(NAME):		
		@$(CC) -o $(NAME) $(FLAGS) $(SRCS) -I $(INCLUDE) -I $(LIBFT) -L $(LIBFT) -lft

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
