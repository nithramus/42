# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 09:09:29 by bhamidi           #+#    #+#              #
#    Updated: 2017/03/09 16:08:49 by bhamidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CC = gcc
CFLAGS = -Werror -Wextra -Wall
PATH_SRCS = srcs/

SRCS =	asm.c					\
		fill_stable.c			\
		free_funct.c			\
		ft_putuchar_fd.c		\
		ft_spec_atoi.c			\
		ft_split_whitespaces.c	\
		ft_strsplit.c			\
		ft_white.c				\
		funct_op_tab.c			\
		get_op_tab.c			\
		get_symb.c				\
		handle_line.c			\
		increment_octet.c		\
		lexical_parse.c			\
		opcode_test.c			\
		opcode_test2.c			\
		parsing.c				\
		print.c					\
		put_option.c			\
		tab_funct.c				\
		write_infile.c			\
		write_opcode.c

OBJS = $(SRCS:.c=.o)

SRC = $(addprefix $(PATH_SRCS),$(SRCS))

all: $(NAME)

$(NAME): $(SRC)
	make -C ./libft/
	make -C ./ft_printf/
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) ./libft/libft.a ./ft_printf/libftprintf.a 

clean:
	make clean -C ./libft/
	make clean -C ./ft_printf/
	/bin/rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft/
	make fclean -C ./ft_printf/
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
