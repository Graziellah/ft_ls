# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 22:31:41 by ghippoda          #+#    #+#              #
#    Updated: 2017/09/21 14:08:01 by ghippoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = ./srcs/main.c ./srcs/option.c ./srcs/file_list.c ./srcs/access.c\
	   ./srcs/aff.c ./srcs/manage_list.c ./srcs/help_aff.c ./srcs/aff_tool.c\
	   ./srcs/sort_tool.c ./srcs/tool_main.c ./srcs/sort_arg.c \
	   ./srcs/sort_arg_tool.c ./srcs/bonus.c

FLAGS = -Wall -Wextra -Werror

FLAGS_LIB = -L./libft -lft

OBJ = ./srcs/main.o ./srcs/option.o ./srcs/file_list.o ./srcs/access.o \
	  ./srcs/aff.o ./srcs/manage_list.o ./srcs/help_aff.o ./srcs/aff_tool.o\
	   ./srcs/sort_tool.o ./srcs/tool_main.o ./srcs/sort_arg.o \
	   ./srcs/sort_arg_tool.o ./srcs/bonus.o

HEADER = ./includes/

LIB = libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compilation du projet"
	@make -C libft
	@echo "apres Compilation libft"
	@gcc $(FLAGS_LIB) $(OBJ) -o $(NAME)
	@echo "Done"

%o: %c
	@gcc -g -I$(HEADER) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft
	@echo "Nettoyage effectue"

re: fclean all
