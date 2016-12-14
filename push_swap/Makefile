# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bandre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 16:17:12 by bandre            #+#    #+#              #
#    Updated: 2016/12/12 02:25:23 by bandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

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
		   tri_fusion.o\
		   tri_fusion_ameliore.o\
		   ft_checker_len.o\
		   tri_am.o\

CC = gcc

LIB = libft/libftprintf.a

FLAG = -Wall -Wextra -Werror

PUSH_SWAP = $(addprefix $(SRC_PATH_PUSH_SWAP)/,$(SRC_PUSH_SWAP))
CHECKER = $(addprefix $(SRC_PATH_CHECKER)/,$(SRC_CHECKER))


all: $(NAME)

$(NAME): PUSH $(CHECKER) 
	$(CC) $(FLAG) $(CHECKER) $(LIB) -o $(NAME)

PUSH: $(PUSH_SWAP)
	$(CC) $(FLAG) $(PUSH_SWAP) $(LIB) -o push_swap


%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -f $(addprefix $(SRC_PATH_CHECKER)/,$(SRC_CHECKER))
	rm -f $(PUSH_SWAP)

fclean: clean
	rm -f $(NAME)
	rm -f push_swap

re: fclean all

flag: $(SRC)
	$(CC) $(CHECKER) $(LIB) -o $(NAME)


