# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bandre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 16:17:12 by bandre            #+#    #+#              #
#    Updated: 2017/03/11 17:24:56 by msrun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC_PATH = src

SRC = corewar.o\
	  recup_param.o\
	  quit_clean.o\
	  test_valide.o\
	  new_t_joueur.o\
	  new_t_process.o\
	  print_memory.o\
	  boucle_principal.o\
	  show_winner.o\
	  parse_option.o\
	  affichage.o\
	  gestion_evem.o\
	  ft_add.o\
	  ft_aff.o\
	  ft_aox.o\
	  ft_aox2.o\
	  ft_aox_d.o\
	  ft_aox_i.o\
	  ft_aox_r.o\
	  ft_aox_tools.o\
	  ft_fork_lfork.o\
	  ft_ldi.o\
	  ft_ldi_par.o\
	  ft_ldi_par2.o\
	  ft_live.o\
	  ft_load.o\
	  ft_sti.o\
	  ft_sti2.o\
	  ft_store.o\
	  ft_sub.o\
	  ft_tools.o\
	  ft_tools2.o\
	  ft_zjmp.o\
	  op.o\

CC = gcc

LIB =  libft/libftprintf.a `sdl-config  --libs` ../libsdl/lib/libSDL_ttf.dylib

FLAG = -Wall -Wextra -Werror

SRC_O = $(addprefix $(SRC_PATH)/,$(SRC))

all: EXEC $(NAME)

$(NAME): $(SRC_O)
	$(CC) -o $(NAME) $(SRC_O) $(LIB)  -I ../bhamidi_va_rm_rf/corewar.h

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

.PHONY: $(NAME) all %.o clean fclean re flag EXEC
