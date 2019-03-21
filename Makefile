# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ispirido <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 21:19:19 by ispirido          #+#    #+#              #
#    Updated: 2018/05/11 13:07:14 by ispirido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = GNL
HEADER = ../get_next_line2/get_next_line.h
FLAGS = -g -Wall -Wextra -Werror
SRCS =../get_next_line2/get_next_line.c main.c
LIB = libft/libft.a
all: $(NAME)
$(LIB):
    @make -C libft
$(NAME): $(LIB)
    @gcc $(FLAGS) $(SRCS) $(LIB) -I $(HEADER) -o $(NAME)
clean:
    @make -C libft clean
fclean: clean
    @rm -rf $(NAME)
    @make -C libft fclean
re: fclean all
