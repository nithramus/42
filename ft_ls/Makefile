# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bandre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 16:17:12 by bandre            #+#    #+#              #
#    Updated: 2017/05/03 19:23:58 by bandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_PATH = ls_src

SRC = ft_ls.o\
	  get_option.o\
	  quit_clean.o\
	  test.o\
	  path_mov.o\
	  sort.o\

CC = gcc

LIB =  libft/libftprintf.a

FLAG = -Wall -Wextra -Werror -O

SRC_O = $(addprefix $(SRC_PATH)/,$(SRC))

all: EXEC $(NAME)

$(NAME): $(SRC_O)
	$(CC) -o $(NAME) $(SRC_O) $(LIB)

EXEC: 
	make -C libft

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(addprefix $(SRC_PATH)/,$(SRC))
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

flag: $(SRC)
	$(CC) $(NAME) $(LIB) -o $(NAME)

do: all
	./ft_ls


.PHONY: $(NAME) all %.o clean fclean re flag EXEC
