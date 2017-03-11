# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 11:40:52 by bhamidi           #+#    #+#              #
#    Updated: 2017/03/07 18:46:48 by bhamidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -Wall -Werror -Wextra

SRCS = srcs/ft_printf.c			\
	   srcs/ft_putchar.c		\
	   srcs/type_spec.c			\
	   srcs/ft_int_parsing.c	\
	   srcs/type_arg.c			\
	   srcs/type_arg1.c			\
	   srcs/add_putwchar.c		\
	   srcs/ft_dernier_parse.c	\
	   srcs/ft_memset.c			\
	   srcs/type_arg_u.c		\
	   srcs/print_arg.c			\
	   srcs/print_strwchar.c	\
	   srcs/ft_itoa_base.c		\
	   srcs/ft_itoa.c			\
	   srcs/ft_putstr.c			\
	   srcs/ft_strchr.c			\
	   srcs/ft_long_file.c		\
	   srcs/char_config.c		\
	   srcs/ft_putendl.c 		\
	   srcs/ft_strdel.c 		\
	   srcs/parse.c 			\
	   srcs/ft_put_hexa_nbr.c	\
	   srcs/ft_atoi_printf.c 	\
	   srcs/ft_uitoa.c 			\
	   srcs/ft_strncpy.c 		\
	   srcs/ft_strcpy.c 		\
	   srcs/ft_strcmp.c 		\
	   srcs/ft_strcat.c 		\
	   srcs/ft_get_len_arg.c 	\
	   srcs/ft_putnbr_ll.c 		\
	   srcs/ft_putnbr_ull.c 	\
	   srcs/parse_ui.c 			\
	   srcs/info_function.c 	\
	   srcs/ft_strdup.c 		\
	   srcs/ft_strrev.c 		\
	   srcs/ft_strrchr.c 		\
	   srcs/ft_toupper.c 		\
	   srcs/ft_strjoin.c 		\
	   srcs/ft_int_more.c 		\
	   srcs/ft_strnew.c 		\
	   srcs/ft_strsub.c 		\
	   srcs/ft_strlen.c

OBJ = ft_printf.o 			\
	  ft_putchar.o	 		\
	  ft_dernier_parse.o	\
	  ft_int_parsing.o		\
	  ft_get_len_arg.o		\
	  char_config.o			\
	  ft_strdup.o 			\
	  parse_ui.o 			\
	  ft_strcat.o 			\
	  add_putwchar.o 		\
	  ft_long_file.o		\
	  ft_int_more.o			\
	  ft_toupper.o 			\
	  ft_strnew.o 			\
	  parse.o 				\
	  type_arg.o 			\
	  ft_itoa_base.o		\
	  ft_itoa.o				\
	  ft_uitoa.o			\
	  type_spec.o 			\
	  print_strwchar.o		\
	  type_arg1.o 			\
	  type_arg_u.o 			\
	  ft_strrev.o			\
	  ft_strchr.o			\
	  ft_memset.o			\
	  ft_strjoin.o			\
	  ft_putnbr_ull.o		\
	  ft_putnbr_ll.o		\
	  ft_put_hexa_nbr.o 	\
	  print_arg.o 			\
	  ft_strdel.o 			\
	  ft_strsub.o 			\
	  ft_atoi_printf.o		\
	  ft_strrchr.o 			\
	  ft_strncpy.o 			\
	  ft_strcpy.o 			\
	  ft_strcmp.o 			\
	  info_function.o		\
	  ft_putendl.o 			\
	  ft_putstr.o 			\
	  ft_strlen.o

all: $(NAME)

$(NAME):
	$(CC) -c $(SRCS)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
