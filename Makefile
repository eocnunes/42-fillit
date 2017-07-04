# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 14:14:26 by enunes            #+#    #+#              #
#    Updated: 2017/07/04 15:54:40 by enunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = 	fillit.c \
		read_tetriminos.c \

OBJS = $(SRCS:.c=.o)

INCLUDE = includes/libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS): %.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)		
		@$(CC) -o $(NAME) $(FLAGS) $(OBJS) -I includes/ -L libft/ -lft

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
