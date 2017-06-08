# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 22:31:41 by ghippoda          #+#    #+#              #
#    Updated: 2017/06/08 02:30:02 by ghippoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = ./srcs/test.c ./srcs/option.c ./srcs/file_list.c\

FLAGS = -Wall -Wextra -Werror -Ofast

FLAGS_LIB = -L./libft -lft

OBJ = ./srcs/test.o ./srcs/option.o ./srcs/file_list.o

HEADER = ./include/

LIB = libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAGS_LIB) $(OBJ) -o $(NAME)

%o: %c
	gcc $(FLAGS) -I$(HEADER) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft

re: fclean all
