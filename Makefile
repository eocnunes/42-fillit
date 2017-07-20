# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 14:14:26 by enunes            #+#    #+#              #
#    Updated: 2017/07/19 15:36:18 by enunes           ###   ########.fr        #
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
		solve_caller.c \

OBJS = $(SRCS:.c=.o)

INCLUDE = includes/

LIBFT = libft/

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -I includes -I libft/

all: $(NAME)

%.o: %.c
		@$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OBJS)
		@$(CC) -o $(NAME) $(FLAGS) $(OBJS) -I $(INCLUDE) -I $(LIBFT) -L $(LIBFT) -lft

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
