# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bandre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 16:17:12 by bandre            #+#    #+#              #
#    Updated: 2017/01/14 20:03:13 by bandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRC_PATH = src

SRC = create_graph.o\
	  graphe_join.o\
	  lem_in.o\
	  new_g_struct.o\
	  graphchr.o\
	  ptr_join.o\
	  is_in_list.o\
	  find_path.o\
	  path_join.o\
	  new_f_path.o\
	  make_dependance.o\
	  path_combinaison.o\
	  test_nbtour.o\
	  afficher.o\
	  fourmis_chemins.o\

CC = gcc

LIB =  libft/libftprintf.a

FLAG = -Wall -Wextra -Werror

SRC_O = $(addprefix $(SRC_PATH)/,$(SRC))

all: EXEC $(NAME)

$(NAME): $(SRC_O)
	$(CC) $(FLAG) -o $(NAME) $(SRC_O) $(LIB)

EXEC: 
	make -C libft

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -f $(addprefix $(SRC_PATH)/,$(SRC))
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

flag: $(SRC)
	$(CC) $(NAME) $(LIB) -o $(NAME)

.PHONY: $(NAME) all %.o clean fclean re flag EXEC
