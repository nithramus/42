# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msrun <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/09 14:01:16 by msrun             #+#    #+#              #
#    Updated: 2017/03/09 14:42:19 by msrun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = desassembleur

CC = gcc
CFLAGS = -Werror -Wextra -Wall

SRCS = ft_putnbr_fd.c ft_putunbr_fd.c ft_strcmp.c ft_strlen.c reverse_asm.c \
	   reverse_little_op_comb.c reverse_little_op_comb2.c reverse_op.c \
	   reverse_op_comb.c reverse_op_comb2.c reverse_op_ft.c reverse_op_ft2.c \
	   reverse_op_ft3.c reverse_op_ft4.c reverse_op_ft5.c reverse_tool.c

INCLUDE = op.h reverse_asm.h

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f 

fclean: clean
	rm -f $(NAME)

re: fclean all
