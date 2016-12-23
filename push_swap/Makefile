# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bandre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 16:17:12 by bandre            #+#    #+#              #
#    Updated: 2016/12/14 01:40:48 by bandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

PUSH = push_swap

SRC_PATH_CHECKER = src_checker

SRC_PATH_PUSH_SWAP = src_push_swap

SRC_CHECKER = checker.o\
		   ft_new_checker.o\
		   test_erreurs.o\
		   ft_free_checker.o\
		   new_list.o\
		   op_swap.o\
		   op_push.o\
		   op_rotate.o\
		   op_reverse_rotate.o\

SRC_PUSH_SWAP = push_swap.o\
		   ft_new_checker.o\
		   test_erreurs.o\
		   ft_free_checker.o\
		   new_list.o\
		   op_swap.o\
		   op_push.o\
		   op_rotate.o\
		   op_reverse_rotate.o\
		   tri_fusion_ameliore.o\
		   ft_checker_len.o\
		   tri_am.o\
		   fusion_recursiv.o\
		   tri_double_extend.o\
		   tri_recursif.o\
		   op_recursif.o\
		   op_recursif_s.o\

CC = gcc

LIB =  libft/libftprintf.a

FLAG = -Wall -Wextra -Werror

PUSH_SWAP = $(addprefix $(SRC_PATH_PUSH_SWAP)/,$(SRC_PUSH_SWAP))
CHECKER = $(addprefix $(SRC_PATH_CHECKER)/,$(SRC_CHECKER))


all: EXEC $(NAME) $(PUSH)

$(NAME): $(CHECKER)
	$(CC) -o $(NAME) $(CHECKER) $(LIB)

$(PUSH): $(PUSH_SWAP)
	$(CC) -o $(PUSH) $(PUSH_SWAP) $(LIB) 

EXEC: 
	make -C libft

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(addprefix $(SRC_PATH_CHECKER)/,$(SRC_CHECKER))
	rm -f $(PUSH_SWAP)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f push_swap
	make -C libft fclean

re: fclean all

flag: $(SRC)
	$(CC) $(CHECKER) $(LIB) -o $(NAME)

.PHONY: NAME all PUSH %.o clean fclean re flag EXEC
