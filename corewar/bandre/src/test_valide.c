/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:47:47 by bandre            #+#    #+#             */
/*   Updated: 2017/03/11 15:50:54 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_joueur		**g_list_joueurs;

static void		read_int(int fd, unsigned int value)
{
	char			buff[4];
	char			test[4];
	int				result;
	unsigned int	*header;

	result = read(fd, buff, 4);
	if (result != 4)
		quit_clean(3);
	test[0] = buff[3];
	test[1] = buff[2];
	test[2] = buff[1];
	test[3] = buff[0];
	header = (unsigned int*)test;
	if (*header != value)
		quit_clean(3);
}

static void		read_four(int fd)
{
	char	buff[4];
	int		result;

	result = read(fd, buff, 4);
	if (result != 4)
		quit_clean(3);
}

static void		test_name(int fd, int num_joueur)
{
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
	int		result;

	result = read(fd, name, PROG_NAME_LENGTH);
	if (result != PROG_NAME_LENGTH)
		quit_clean(3);
	name[PROG_NAME_LENGTH] = '\0';
	read_int(fd, 0);
	read_four(fd);
	result = read(fd, comment, COMMENT_LENGTH);
	if (result != COMMENT_LENGTH)
		quit_clean(3);
	comment[COMMENT_LENGTH] = '\0';
	read_int(fd, 0);
	if (!(g_list_joueurs = (t_joueur**)ft_ptradd_free((void**)g_list_joueurs,
					new_t_joueur(name, comment, num_joueur))))
		quit_clean(1);
}

int				test_valide(int fd, int num_joueur)
{
	read_int(fd, COREWAR_EXEC_MAGIC);
	test_name(fd, num_joueur);
	return (1);
}
