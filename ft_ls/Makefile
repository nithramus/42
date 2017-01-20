# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bandre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 16:17:12 by bandre            #+#    #+#              #
#    Updated: 2017/01/16 11:22:00 by bandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_PATH = src

SRC = ft_ls.o\
	  new_s_param.o\
	  recup_param.o\
	  ft_free.o\
	  afficher_error.o\

CC = gcc

LIB =  libft/libftprintf.a

FLAG = -Wall -Wextra -Werror

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
