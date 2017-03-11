# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 19:47:55 by bhamidi           #+#    #+#              #
#    Updated: 2017/03/07 18:56:26 by bhamidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	   ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	   ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c  \
	   ft_putchar_fd.c  ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c  \
	   ft_putstr_fd.c  ft_strclr.c  \
	   ft_strequ.c ft_striter.c ft_striteri.c  ft_strlcat.c  ft_strmap.c ft_strmapi.c \
	   ft_strncat.c ft_strncmp.c ft_strnequ.c  ft_strnstr.c  \
	   ft_strstr.c  ft_strtrim.c ft_tolower.c  ft_get_nb_word.c  \
	   ft_lstpush_back.c get_next_line.c


OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)

clean :
	@/bin/rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
